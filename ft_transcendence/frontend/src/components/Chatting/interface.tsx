import { Socket } from "socket.io-client";
import { ChannelStatus } from "../Channels/interface";
import { ProfileProps } from '../Profile';

export enum MemberType {
  OWNER = "OWNER",
  ADMIN = "ADMIN",
  MEMBER = "MEMBER",
}

export interface ChannelMembers {
  userId: number;
  channelId: number;
  nickname: string;
  type: MemberType;
  avatar: any;
}

export interface HowMany {
  connectedSockets: number;
  joinMembers: number;
}

export interface ChannelInfo {
  channelStatus: ChannelStatus;
  channelMembers: ChannelMembers[];
  myType: MemberType;
  title: string;
  howmany: HowMany;
}

export interface ChatData {
  channelId: number;
  content: string;
  createdAt: string;
  id: number;
  senderUserId: number;
  senderUserNickname: string;
}

export interface Chat {
  user: string;
  imgSrc: string;
  content: string;
  createdAt: string;
}

export interface ChatProps {
  channelInfo: ChannelInfo;
  chat: ChatData;
  isMe: boolean;
  idAvatarMap: Map<number, Blob>;
  socket: Socket | undefined;
  setPopProfile: React.Dispatch<React.SetStateAction<boolean>>;
  setUser: React.Dispatch<React.SetStateAction<ProfileProps | null>>;
}

export interface Member {
  userId: number;
  channelId: number;
}
