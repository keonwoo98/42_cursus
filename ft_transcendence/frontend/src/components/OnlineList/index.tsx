import { useCallback, useContext, useEffect, useState } from "react";
import { Scrollbars } from "react-custom-scrollbars";
import { useNavigate } from "react-router";
import IconButton from "@mui/material/IconButton";
import ChatIcon from "@mui/icons-material/Chat";
import {
  FriendListContainer,
  OnOffLineList,
  Header,
  UserStatus,
  SingleUser,
} from "./styles";
import InviteButton from "./InviteButton";
import { useSendDm } from "../../hooks/mutation/chat";
import { SocketContext } from "../../contexts/ClientSocket";

export enum ClientStatus {
  ONLINE = "ONLINE",
  INGAME = "INGAME",
  OFFLINE = "OFFLINE",
}

interface Status {
  userId: number;
  status: ClientStatus;
}

export interface User {
  id: number;
  nickname: string;
  status: ClientStatus;
}

const OnlineList = ({
  isHome,
  setChannelId,
  setPopChatting,
}: {
  isHome: boolean;
  setChannelId: React.Dispatch<React.SetStateAction<string>> | null;
  setPopChatting: React.Dispatch<React.SetStateAction<boolean>> | null;
}) => {
  const clientSocket = useContext(SocketContext);
  const navigate = useNavigate();
  const sendDM = useSendDm();
  const [friendList, setFriendList] = useState<User[]>([]);

  useEffect(() => {
    clientSocket.on("friends_status", (data: User[]) => {
      setFriendList(data);
    });
    clientSocket.emit("friends_status");

    return () => {
      clientSocket.off("friends_status");
    };
  }, []);

  useEffect(() => {
    clientSocket.on("change_status", (data: Status) => {
      setFriendList((prevFriendList) => {
        const newFriendList: User[] = prevFriendList.map((friend) => {
          if (friend.id === data.userId) {
            return {
              ...friend,
              status: data.status,
            };
          } else {
            return friend;
          }
        });
        return newFriendList;
      });
    });

    return () => {
      clientSocket.off("change_status");
    };
  }, []);

  const onClickSendDm = useCallback((userinfo: User) => {
    if (isHome) {
      navigate("/chat", {
        state: { user: userinfo },
      });
    } else {
      sendDM.mutate({
        id: userinfo.id,
        nickname: userinfo.nickname,
        setChannelId: setChannelId,
        setPopChatting: setPopChatting,
      });
    }
  }, []);

  return (
    <FriendListContainer>
      <OnOffLineList className="Online">
        <Header>ONLINE</Header>
        <Scrollbars autoHide style={{}} onScrollFrame={() => {}}>
          {friendList?.map((userinfo: User) => {
            if (userinfo?.status === "ONLINE" || userinfo?.status === "INGAME")
              return (
                <SingleUser key={userinfo.id}>
                  <UserStatus status={userinfo.status} />
                  <div className="userName">{userinfo.nickname}</div>
                  <IconButton
                    color="success"
                    size="small"
                    edge="end"
                    onClick={() => onClickSendDm(userinfo)}
                  >
                    <ChatIcon className="icon" />
                  </IconButton>
                  <InviteButton socket={clientSocket} userinfo={userinfo} />
                </SingleUser>
              );
          })}
        </Scrollbars>
      </OnOffLineList>
      <OnOffLineList className="Offline">
        <Header>OFFLINE</Header>
        <Scrollbars autoHide style={{}} onScrollFrame={() => {}}>
          {friendList?.map((userinfo: User) => {
            if (userinfo?.status !== "ONLINE" && userinfo?.status !== "INGAME")
              return (
                <SingleUser key={userinfo.id}>
                  <UserStatus status={userinfo.status} />
                  {userinfo.nickname}
                  <IconButton
                    color="success"
                    size="small"
                    edge="end"
                    onClick={() => onClickSendDm(userinfo)}
                  >
                    <ChatIcon className="icon" />
                  </IconButton>
                </SingleUser>
              );
          })}
        </Scrollbars>
      </OnOffLineList>
    </FriendListContainer>
  );
};

export default OnlineList;
