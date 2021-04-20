

/*

  Author: Ícaro Fernando
  github: https://github.com/icarofcb
  
  Date: 12/03/2021

  /*
       72E6(Mhz)  
  f = ----------- 
        ps x of     
  
  ps: prescaler
  of: overflow
  
*/

#define pwm1 PA10

 
unsigned duty1     =       0;                  //armazena valor do duty cycle
unsigned frequency =       2,                  //armazena opção de frequência
         overflow  =   36000,                  //armazena valor de estouro
         pscaler   =       2;                  //armazena valor de prescaler
         
void setup() {
   pinMode(pwm1,    PWM);                      //saída para o pwm1

  HardwareTimer timer(1);                      //seleciona Timer1
  timer.setPrescaleFactor(pscaler);            //prescaler Timer1 = 1:2
  timer.setOverflow(overflow);                 //Timer1 overflow = 36000
  pwmWrite(pwm1, duty1);                       //inicializa PWM com duty1 de 0

 
  timer.setPrescaleFactor(pscaler);            //atualiza prescaler
  timer.setOverflow(overflow);                 //atualiza overflow

  duty1 = overflow>>1;                         //inicia duty em 50%
  pwmWrite(pwm1, duty1);                       //atualiza PWM
                                               //f = (72E6) / (2 x 36000) = 1kHz
                                         
}

void loop() {
   
}
