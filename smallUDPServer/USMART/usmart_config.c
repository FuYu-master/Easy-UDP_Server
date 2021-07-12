#include "usmart.h"
#include "usmart_str.h"	   
////////////////////////////�û�������///////////////////////////////////////////////
//������Ҫ�������õ��ĺ�����������ͷ�ļ�(�û��Լ�����) 
#include "delay.h"	
#include "usart.h"		
#include "sys.h"
#include "lcd.h"
#include "sram.h"
#include "malloc.h"
#include "dm9000.h"
 
//�������б���ʼ��(�û��Լ�����)
//�û�ֱ������������Ҫִ�еĺ�����������Ҵ�
struct _m_usmart_nametab usmart_nametab[]=
{
#if USMART_USE_WRFUNS==1 	//���ʹ���˶�д����
	(void*)read_addr,"u32 read_addr(u32 addr)",
	(void*)write_addr,"void write_addr(u32 addr,u32 val)",	 
#endif
	(void*)delay_ms,"void delay_ms(u16 nms)",
	(void*)delay_us,"void delay_us(u32 nus)",	 
	(void*)DM9000_ReadReg,"uint8_t DM9000_ReadReg(uint8_t reg)",
	(void*)DM9000_WriteReg,"void DM9000_WriteReg(uint8_t reg,uint8_t data)",
	(void*)DM9000_PHY_ReadReg,"uint16_t DM9000_PHY_ReadReg(uint8_t reg)",
	(void*)DM9000_PHY_WriteReg,"void DM9000_PHY_WriteReg(uint8_t reg,uint16_t data)",
};						  
///////////////////////////////////END///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//�������ƹ�������ʼ��
//�õ������ܿغ���������
//�õ�����������
struct _m_usmart_dev usmart_dev=
{
	usmart_nametab,
	usmart_init,
	usmart_cmd_rec,
	usmart_exe,
	usmart_scan,
	sizeof(usmart_nametab)/sizeof(struct _m_usmart_nametab),//��������
	0,	  	//��������
	0,	 	//����ID
	1,		//������ʾ����,0,10����;1,16����
	0,		//��������.bitx:,0,����;1,�ַ���	    
	0,	  	//ÿ�������ĳ����ݴ��,��ҪMAX_PARM��0��ʼ��
	0,		//�����Ĳ���,��ҪPARM_LEN��0��ʼ��
};   


















