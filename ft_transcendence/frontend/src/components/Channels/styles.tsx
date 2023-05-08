import styled from "styled-components";

export const ChannelContainer = styled.div`
  --channel-width: calc(var(--section-width));
  --channel-height: calc(var(--section-height) * 0.9);
  --channel-padding: var(--section-padding);

  --header-height: var(--fontsize-big);
  --header-width: calc(
    var(--channel-width) - 2 * (var(--channel-padding) + var(--border-width))
  );

  box-sizing: border-box;
  width: var(--channel-width);
  height: var(--channel-height);
  border-radius: calc(var(--channel-height) * 0.05);
  border: var(--border-width) solid black;
  padding: calc(var(--channel-padding) / 3) var(--channel-padding);

  display: flex;
  flex-direction: column;
  overflow: hidden;

  background: rgba(255, 255, 255, 0.2);
  backdrop-filter: blur(5px);
`;

export const SearchChannel = styled.form`
  --button-size: min(
    calc(var(--header-width) * 0.18),
    calc(var(--header-height) * 0.7)
  );

  box-sizing: border-box;
  width: var(--header-width);
  height: var(--header-height);
  display: flex;
  align-items: center;
  gap: calc(var(--button-size) * 0.1);

  & > input {
    box-sizing: boarder-box;
    display: inline-block;
    width: calc(var(--header-width) - 2.4 * var(--button-size));
    height: calc(var(--header-height) * 0.6);
    border-radius: calc(var(--header-height) * 0.3);
    border: calc(var(--border-width) / 2) solid black;
    padding: 0;
    padding-left: calc(var(--h) * 0.15);
    background-color: var(--color-gray);
  }
  & > button {
    box-sizing: boarder-box;
    height: var(--button-size);
    width: var(--button-size);
    aspect-ratio: 1;
    border: calc(var(--border-width) / 2) solid black;
    cursor: pointer;
  }
`;

export const ChannelList = styled.div`
  --list-padding: calc(var(--channel-padding) * 0.5);
  --list-width: var(--header-width);
  --h: 100%;

  box-sizing: border-box;
  width: var(--list-width);
  height: var(--h);
  padding: var(--list-padding) 0;
  line-height: var(--fontsize-small);
  font-size: var(--fontsize-small);
  overflow-y: auto;

  & .eachChannel {
    --single-channel-height: calc(3 * var(--fontsize-small));
    box-sizing: border-box;

    width: 100%;
    height: var(--single-channel-height);

    background: white;
    border-radius: calc(var(--single-channel-height) / 3);
    border: calc(var(--border-width) / 2) solid black;
    padding: calc(var(--single-channel-height) * 0.125);
    padding-left: calc(var(--single-channel-height) * 0.25);
    margin-bottom: calc(var(--single-channel-height) * 0.125);

    font-size: var(--fontsize-small);
    font-weight: var(--fontweight-small);
    text-align: left;
    cursor: pointer;

    &:hover {
      opacity: 0.9;
      transform: scale(0.98);
    }

    & > .channelName {
      display: flex;
      flex-direction: row;
      font-weight: 600;
      white-space: nowrap;
      --lockimg-size: var(--fontsize-small);
      width: var(--lockimg-size);
      height: var(--lockimg-size);
      & > img {
        width: 100%;
        height: 100%;
      }
    }
    & > .ownerName {
      text-align: right;
      color: gray;
    }
  }
`;

export const Input = styled.input`
  border: 0.3rem solid black;
  border-radius: 2rem;
  background-color: yellow;
  padding: 1rem;
  margin: 1rem;
`;

export const Header = styled.div`
  width: var(--header-width);
  height: var(--header-height);
  line-height: var(--fontsize-big);
  font-size: var(--fontsize-big);
  font-weight: var(--fontweight-big);
`;

// Modal child
export const ModalChild = styled.form`
  background-color: pink;
  margin-top: calc(var(--modal-width) * 0.05);
  width: calc(var(--modal-width) * 0.9);
  height: var(--modal-width);

  border-radius: calc(var(--modal-width) * 0.05);
  border: var(--border-width) solid black;

  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;

  Input {
    width: calc(var(--modal-width) * 0.8);
    height: calc(var(--fontsize-big) * 1.5);
    background-color: white;
    border: calc(var(--border-width) / 1.5) solid black;

    margin: 0;
    margin-bottom: calc(var(--modal-width) * 0.1);
    padding: 0;
    padding-left: calc(var(--fontsize-big) * 0.5);

    font-size: calc(var(--fontsize-big) / 1.5);
  }

  button {
    margin-top: calc(var(--modal-width) * 0.1);

    width: calc(var(--modal-width) * 0.3);
    height: calc(var(--modal-width) * 0.2);
    background-color: yellow;
    border: calc(var(--border-width) / 1.5) solid black;
    > img {
      width: calc(var(--modal-width) * 0.15);
    }
  }
`;
