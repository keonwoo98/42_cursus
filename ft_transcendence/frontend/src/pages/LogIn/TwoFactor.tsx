import { useCallback, useState, useEffect, useRef } from 'react';
import { useValidate2FA } from '../../hooks/mutation/user';
import { Container, Label, TwoFactorSingleInput, TwoFactorInputContainer, Conflict, Form } from './styles';
import { BigButton } from '../../components/Button';
import Title from '../../components/Title';
import loginButton from '../../assets/bigButton/2FALoginButton.svg';

const TwoFactor = () => {
  const validate2FA = useValidate2FA();
  const [password, setPassword] = useState('');
  const ref1 = useRef<HTMLInputElement>(null);
  const ref2 = useRef<HTMLInputElement>(null);
  const ref3 = useRef<HTMLInputElement>(null);
  const ref4 = useRef<HTMLInputElement>(null);
  const ref5 = useRef<HTMLInputElement>(null);
  const ref6 = useRef<HTMLInputElement>(null);
  const [twoFactorError, setTwoFactorError] = useState(false);

  const handleOnChange = useCallback((index: number, value: string) => {
    if (value.length === 1 && !isNaN(Number(value))) {
      setPassword((prevPassword) => {
        const newPassword = prevPassword.slice(0, index) + value + prevPassword.slice(index + 1);
        return newPassword;
      });
      switch (index) {
        case 0:
          ref2.current?.focus();
          break;
        case 1:
          ref3.current?.focus();
          break;
        case 2:
          ref4.current?.focus();
          break;
        case 3:
          ref5.current?.focus();
          break;
        case 4:
          ref6.current?.focus();
          break;
        case 5:
          ref6.current?.blur();
          break;
        default:
          break;
      }
    } else {
      setPassword((prevPassword) => {
        const newPassword = prevPassword.slice(0, index) + prevPassword.slice(index + 1);
        return newPassword;
      });
    }
    if (twoFactorError) {
      setTwoFactorError(false);
    }
  }, [twoFactorError]);

  const onSubmit = useCallback(
    (e: any) => {
      e.preventDefault();
      validate2FA.mutate({ password: password, setTwoFactorError: setTwoFactorError, setPassword: setPassword });
    },
    [validate2FA, password]
  );

  useEffect(() => {
    ref1.current?.focus();
  }, []);

  useEffect(() => {
    if (twoFactorError) {
      ref1.current!.value = '';
      ref2.current!.value = '';
      ref3.current!.value = '';
      ref4.current!.value = '';
      ref5.current!.value = '';
      ref6.current!.value = '';
      ref1.current?.focus();
      setPassword('');
    }
  }, [twoFactorError]);

  return (
    <Container>
      <div className='Title'>
        <Title title='PONG 2FA' />
      </div>
      <div className='Body'>
        <Form onSubmit={onSubmit}>
          <div className='Input'>
            <Label id='password'>
              <p>Google Authenticator</p>
              <TwoFactorInputContainer>
                <TwoFactorSingleInput type='text' maxLength={1} ref={ref1} onChange={(event) => handleOnChange(0, event.target.value)} />
                <TwoFactorSingleInput type='text' maxLength={1} ref={ref2} onChange={(event) => handleOnChange(1, event.target.value)} />
                <TwoFactorSingleInput type='text' maxLength={1} ref={ref3} onChange={(event) => handleOnChange(2, event.target.value)} />
                <TwoFactorSingleInput type='text' maxLength={1} ref={ref4} onChange={(event) => handleOnChange(3, event.target.value)} />
                <TwoFactorSingleInput type='text' maxLength={1} ref={ref5} onChange={(event) => handleOnChange(4, event.target.value)} />
                <TwoFactorSingleInput type='text' maxLength={1} ref={ref6} onChange={(event) => handleOnChange(5, event.target.value)} />
              </TwoFactorInputContainer>
            </Label>
            {twoFactorError && (
              <Conflict>2FA authentication failed. Please try again.</Conflict>
            )}
          </div>
          <div className='BigButtons'>
            <BigButton img_url={loginButton} type='submit' />
          </div>
        </Form>
      </div>
    </Container>
  );
};

export default TwoFactor;
