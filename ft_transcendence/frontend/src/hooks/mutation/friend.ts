import { useContext } from "react";
import { useFetcher } from "../fetcher";
import {
  useMutation,
  UseMutationResult,
  MutationFunction,
  useQueryClient,
} from "react-query";
import { SocketContext } from "../../contexts/ClientSocket";
import { toast } from "react-toastify";

export function useAddFriend(): UseMutationResult<
  void,
  Error,
  number,
  MutationFunction<void, number>
> {
  const queryClient = useQueryClient();
  const fetcher = useFetcher();
  const clientSocket = useContext(SocketContext);

  async function addFriend(id: number): Promise<void> {
    await fetcher("/users/friends/request/" + id, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      credentials: "include",
    }).then((response) => {
      if (response.status === 201) {
        clientSocket.emit("sendFriendRequest", id);
        toast.success("Friend requested");
      }
    });
  }

  return useMutation({
    mutationFn: addFriend,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ["userPendingFriendList"] });
    },
  });
}

export function useApproveFriend(): UseMutationResult<
  void,
  Error,
  number,
  MutationFunction<void, number>
> {
  const queryClient = useQueryClient();
  const fetcher = useFetcher();
  const clientSocket = useContext(SocketContext);

  async function approveFriend(id: number): Promise<void> {
    await fetcher("/users/friends/approve/" + id, {
      method: "PUT",
      headers: {
        "Content-Type": "application/json",
      },
      credentials: "include",
    }).then((response) => {
      if (response.status === 200) {
        clientSocket.emit("friends_status");
        clientSocket.emit("sendFriendRequest", id);
        toast.success("Approved request");
      }
    });
  }

  return useMutation({
    mutationFn: approveFriend,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ["userFriendList"] });
      queryClient.invalidateQueries({ queryKey: ["userReceivedFriendList"] });
    },
  });
}

export function useRefuseFriend(): UseMutationResult<
  void,
  Error,
  number,
  MutationFunction<void, number>
> {
  const queryClient = useQueryClient();
  const fetcher = useFetcher();
  const clientSocket = useContext(SocketContext);

  async function refuseFriend(id: number): Promise<void> {
    await fetcher("/users/friends/received/" + id, {
      method: "DELETE",
      headers: {
        "Content-Type": "application/json",
      },
      credentials: "include",
    }).then((response) => {
      if (response.status === 200) {
        toast.success("Refused request");
        clientSocket.emit("sendFriendRequest", id);
      }
    });
  }

  return useMutation({
    mutationFn: refuseFriend,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ["userReceivedFriendList"] });
    },
  });
}

export function useDeleteRequestFriend(): UseMutationResult<
  void,
  Error,
  number,
  MutationFunction<void, number>
> {
  const queryClient = useQueryClient();
  const fetcher = useFetcher();
  const clientSocket = useContext(SocketContext);

  async function deleteRequestFriend(id: number): Promise<void> {
    await fetcher("/users/friends/request/" + id, {
      method: "DELETE",
      headers: {
        "Content-Type": "application/json",
      },
      credentials: "include",
    }).then((response) => {
      if (response.status === 200) {
        toast.success("Request canceled");
        clientSocket.emit("sendFriendRequest", id);
      }
    });
  }

  return useMutation({
    mutationFn: deleteRequestFriend,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ["userPendingFriendList"] });
    },
  });
}

export function useDeleteFriend(): UseMutationResult<
  void,
  Error,
  number,
  MutationFunction<void, number>
> {
  const queryClient = useQueryClient();
  const fetcher = useFetcher();
  const clientSocket = useContext(SocketContext);

  async function deleteFriend(id: number): Promise<void> {
    await fetcher("/users/friends/" + id, {
      method: "DELETE",
      headers: {
        "Content-Type": "application/json",
      },
      credentials: "include",
    }).then((response) => {
      if (response.status === 200) {
        clientSocket.emit("friends_status");
        clientSocket.emit("sendFriendRequest", id);
        toast.success("Friend deleted");
      }
    });
  }

  return useMutation({
    mutationFn: deleteFriend,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ["userFriendList"] });
    },
  });
}

export function useBlockFriend(): UseMutationResult<
  void,
  Error,
  number,
  MutationFunction<void, number>
> {
  const fetcher = useFetcher();
  const queryClient = useQueryClient();

  async function blockFriend(id: number): Promise<void> {
    await fetcher("/users/friends/request/block/" + id, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      credentials: "include",
    }).then((response) => {
      if (response.status === 201) toast.success("Friend blocked");
    });
  }

  return useMutation({
    mutationFn: blockFriend,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ["channelInfo"] });
      queryClient.invalidateQueries({ queryKey: ["getChats"] });
      queryClient.invalidateQueries({ queryKey: ["myChannels"] });
    }
  });
}

export function useUnblockFriend(): UseMutationResult<
  void,
  Error,
  number,
  MutationFunction<void, number>
> {
  const fetcher = useFetcher();
  const queryClient = useQueryClient();

  async function unblockFriend(id: number): Promise<void> {
    await fetcher("/users/friends/block/" + id, {
      method: "DELETE",
      headers: {
        "Content-Type": "application/json",
      },
      credentials: "include",
    }).then((response) => {
      if (response.status === 200) toast.success("Friend unblocked");
    });
  }

  return useMutation({
    mutationFn: unblockFriend,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ["channelInfo"] });
      queryClient.invalidateQueries({ queryKey: ["getChats"] });
      queryClient.invalidateQueries({ queryKey: ["myChannels"] });
    }
  });
}
