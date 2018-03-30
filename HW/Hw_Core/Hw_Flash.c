#define HW_FLASH_LOCAL

#include "Hw_Flash.h"

HW_FLASH_DEF FLASH_Status FLASH_ProgramWord(uint32_t Address, uint32_t Data);
HW_FLASH_DEF FLASH_Status FLASH_WaitForLastOperation(uint32_t Timeout);
HW_FLASH_DEF FLASH_Status FLASH_GetBank1Status(void);

HW_FLASH_DEF FLASH_Status FLASH_ProgramWord(uint32_t Address, uint32_t Data)
{
    FLASH_Status status = FLASH_COMPLETE;
    __IO uint32_t tmp = 0;
    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation(ProgramTimeout);

    if(status == FLASH_COMPLETE)
    {
        /* if the previous operation is completed, proceed to program the new second
      half word */
      FLASH->CR |= FLASH_CR_PG_Set;
      *(__IO uint16_t *)Address = (uint16_t)Data;
      /* Wait for last operation to be completed */
      status = FLASH_WaitForLastOperation(ProgramTimeout);

      if(status == FLASH_COMPLETE)
      {
          /* if the previous operation is completed, proceed to program the new second
            half word */
            tmp = Address + 2;
            *(__IO uint16_t *)tmp = Data >> 16;
            /* Wait for last operation to be completed */
            status = FLASH_WaitForLastOperation(ProgramTimeout);
            /* Disable the PG Bit */
            FLASH->CR &= FLASH_CR_PG_Reset;
      }
      else{
          /* Disable the PG Bit */
          FLASH->CR &= FLASH_CR_PG_Reset;
      }
    }
    /* Return the Program Status */
    return status;
}

HW_FLASH_DEF FLASH_Status FLASH_WaitForLastOperation(uint32_t Timeout)
{
    FLASH_Status status = FLASH_COMPLETE;
    /* Check for the Flash Status */
    status = FLASH_GetBank1Status();
    /* Wait for a Flash operation to complete or a TIMEOUT to occur */
    while((status == FLASH_BUSY) && (Timeout != 0x00))
    {
        status = FLASH_GetBank1Status();
        Timeout--;
    }
    if(Timeout == 0x00)
    {
        status = FLASH_TIMEOUT;
    }
    /* Return the operation status */
    return status;
}

HW_FLASH_DEF FLASH_Status FLASH_GetBank1Status(void)
{
    FLASH_Status flashstatus = FLASH_COMPLETE;
    if((FLASH->SR & FLASH_FLAG_BANK1_BSY) == FLASH_FLAG_BSY)
    {
        flashstatus = FLASH_BUSY;
    }
    else{
        if((FLASH->SR & FLASH_FLAG_BANK1_PGERR) != 0)
        {
            flashstatus = FLASH_ERROR_PG;
        }
        else{
            if((FLASH->SR & FLASH_FLAG_BANK1_WRPRTERR) != 0)
            {
                flashstatus = FLASH_ERROR_WRP;
            }
            else{
                flashstatus = FLASH_COMPLETE;
            }
        }
    }
    /* Return the Flash Status */
    return flashstatus;
}