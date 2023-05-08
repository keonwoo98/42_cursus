import { useFetcher } from '../fetcher';
import { useMutation, UseMutationResult, MutationFunction, useQueryClient } from 'react-query';
import { Socket } from 'socket.io-client';
import { toast } from 'react-toastify';

interface JoinChannelData {
  id: string;
  password: string;
  socket: Socket | undefined;
  setChannelId: React.Dispatch<React.SetStateAction<string>>;
  setPopChatting: React.Dispatch<React.SetStateAction<boolean>>;
}

export interface CreateChannelData {
  title: string;
  password: string;
}

interface SetChannelPassword {
  id: string;
  password: string;
}

interface PostChatData {
  id: string;
  chat: string;
}

interface SendDMData {
  id: number | undefined;
  nickname: string | undefined;
  setChannelId: React.Dispatch<React.SetStateAction<string>> | null;
  setPopChatting: React.Dispatch<React.SetStateAction<boolean>> | null;
}

interface AKBMData {
  id: string;
  user: string;
}

export function useCreateChannel(): UseMutationResult<void, Error, CreateChannelData, MutationFunction<void, CreateChannelData>> {
  const queryClient = useQueryClient();
  const fetcher = useFetcher();

  async function createChannel(data: CreateChannelData): Promise<void> {
    const { title, password } = data;
    await fetcher('/channels', {
      method: 'POST',
      credentials: 'include',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ title, password })
    })
      .then(response => {
        if (response.status === 201)
          toast.success('New channel created');
        else if (response.status === 400)
          toast.error('Channel name alreay exists')
      })
  }
  return useMutation({
    mutationFn: createChannel,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ['allChannels'] });
      queryClient.invalidateQueries({ queryKey: ['myChannels'] });
    }
  })
}

export function useJoinChannel(): UseMutationResult<void, Error, JoinChannelData, MutationFunction<void, JoinChannelData>> {
  const queryClient = useQueryClient();
  const fetcher = useFetcher();

  async function joinChannel(data: JoinChannelData): Promise<void> {
    const { id, password, socket, setChannelId, setPopChatting } = data;
    await fetcher('/channels/' + id, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      credentials: 'include',
      body: JSON.stringify({ password: password }),
    })
      .then((response) => {
        if (response.status === 200) {
          toast.success('Successfully joined channel');
          socket?.emit('joinChannel', { 'channelId': String(id) });
          setChannelId(id);
          setPopChatting(true);
        }
        else if (response.status === 400)
          toast.error('You are already in the channel');
        else if (response.status === 403)
          toast.error('Wrong password')
        else if (response.status === 406)
          toast.warning('You are banned to this channel');
      });
  }

  return useMutation({
    mutationFn: joinChannel,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ['myChannels'] });
    }
  });
}

export function useSetChannelPassword(): UseMutationResult<void, Error, SetChannelPassword, MutationFunction<void, SetChannelPassword>> {
  const queryClient = useQueryClient();
  const fetcher = useFetcher();

  async function setChannelPassword(data: SetChannelPassword): Promise<void> {
    const { id, password } = data;
    await fetcher('/channels/' + id, {
      method: 'PATCH',
      credentials: 'include',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ password: password })
    })
      .then(response => {
        if (response.status === 200)
          toast.success('Password set successfully');
      })
  }
  return useMutation({
    mutationFn: setChannelPassword,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ['allChannels'] });
      queryClient.invalidateQueries({ queryKey: ['myChannels'] });
    }
  })
}

export function usePostChat(): UseMutationResult<void, Error, PostChatData, MutationFunction<void, PostChatData>> {
  const fetcher = useFetcher();

  async function postChat(data: PostChatData): Promise<void> {
    const { id, chat } = data;
    await fetcher('/chat/' + id, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      credentials: 'include',
      body: JSON.stringify({ content: chat }),
    })
      .then((response) => {
        if (response.status === 406)
          toast.warning('Your are muted for 5 minutes');
      })
  }

  return useMutation(postChat);
}

export function useSendDm(): UseMutationResult<void, Error, SendDMData, MutationFunction<void, SendDMData>> {
  const queryClient = useQueryClient();
  const fetcher = useFetcher();

  async function sendDM(data: SendDMData): Promise<void> {
    const { id, nickname, setChannelId, setPopChatting } = data;
    await fetcher('/channels/dm', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      credentials: 'include',
      body: JSON.stringify({ id: id, nickname: nickname }),
    })
      .then((response) => {
        if (response.status === 201 || response.status === 400) {
          response.json().then(data => {
            if (setChannelId && setPopChatting) {
              setChannelId(data.channelId);
              setPopChatting(true);
            }
          })
        }
        if (response.status === 406)
          toast.error('You blocked ' + nickname);
      })
  }

  return useMutation({
    mutationFn: sendDM,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ['myChannels'] });
    }
  });
}

export function useAdmin(): UseMutationResult<void, Error, AKBMData, MutationFunction<void, AKBMData>> {
  const fetcher = useFetcher();
  const queryClient = useQueryClient();

  async function admin(data: AKBMData): Promise<void> {
    const { id, user } = data;
    await fetcher('/channels/' + id + '/admin/' + user, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      credentials: 'include',
    })
      .then((response) => {
        if (response.status === 200)
          toast.success('Admin privileges have been successfully granted');
        if (response.status === 405)
          toast.warning('User is alreay Administrator');
      })
  }
  return useMutation({
    mutationFn: admin,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ['channelInfo'] });
    }
  });
}

export function useKick(): UseMutationResult<void, Error, AKBMData, MutationFunction<void, AKBMData>> {
  const fetcher = useFetcher();
  const queryClient = useQueryClient();

  async function kick(data: AKBMData): Promise<void> {
    const { id, user } = data;
    await fetcher('/channels/' + id + '/kick/' + user, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      credentials: 'include',
    })
      .then((response) => {
        if (response.status === 200) {
          toast.success('User is kicked out');
        }
      })
  }
  return useMutation({
    mutationFn: kick,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ['channelInfo'] });
    }
  });
}

export function useBan(): UseMutationResult<void, Error, AKBMData, MutationFunction<void, AKBMData>> {
  const fetcher = useFetcher();
  const queryClient = useQueryClient();

  async function ban(data: AKBMData): Promise<void> {
    const { id, user } = data;
    await fetcher('/channels/' + id + '/ban/' + user, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      credentials: 'include',
    })
      .then((response) => {
        if (response.status === 200) {
          toast.success('User is banned in this channel');
        }
      })
  }
  return useMutation({
    mutationFn: ban,
    onSuccess: () => {
      queryClient.invalidateQueries({ queryKey: ['channelInfo'] });
    }
  });
}

export function useMute(): UseMutationResult<void, Error, AKBMData, MutationFunction<void, AKBMData>> {
  const fetcher = useFetcher();

  async function mute(data: AKBMData): Promise<void> {
    const { id, user } = data;
    await fetcher('/channels/' + id + '/mute/' + user, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      credentials: 'include',
    })
      .then((response) => {
        if (response.status === 200)
          toast.success('User has been muted in this channel');
      })
  }
  return useMutation(mute);
}
