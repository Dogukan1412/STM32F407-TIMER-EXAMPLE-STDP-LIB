
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

// default clock speed = 84MHz


void TIM4_Config(void);
uint16_t count;

int main(void)
{
	TIM4_Config();

  while (1)
  {
	  count = TIM_GetCounter(TIM4);                 // this code was written for us to see the counter value from the STM Studio
  }
}


void TIM4_Config(void)               // this configuration counts up to 10000 per second.
{
	TIM_TimeBaseInitTypeDef tim4;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);            // tim4 clock buss is activated

	tim4.TIM_ClockDivision = TIM_CKD_DIV1;                          // default clock speed / divided 1 = 84MHz
	tim4.TIM_CounterMode = TIM_CounterMode_Up;                      // counting up
	tim4.TIM_Period = 9999;                                         //  84 000 000 / ( (9999 + 1) * (8399 + 1) ) = 1 Hertz = 1 second
	tim4.TIM_Prescaler = 8399;
	tim4.TIM_RepetitionCounter = 0;

	TIM_TimeBaseStructInit(&tim4);									// initialized tim4
	TIM_Cmd(TIM4, ENABLE);
}





/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
