/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaudoui <ngaudoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:02:02 by ngaudoui          #+#    #+#             */
/*   Updated: 2025/03/31 19:15:53 by ngaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/** global static int variable. it will help us note 
*   when we stopped receiving signals
*/
static int	signal_end;

void  send_char(char c, pid_t srv)
{
   int   bit;

   bit = 0;
   while (bit < CHAR_BIT)
   {
      if (c & (0b10000000 >> bit))
         KILL(srv, SIGUSR1);
      else
         KILL(srv, SIGUSR2);
      ++bit;
   }
}

void sig_handler(int signum, siginfo_t* info, void* context)
{
  /** 
     *  create a variable static int i to count the numbers of bit read
     *  void the args you are not using
     *
     *  change the global varaible to 1
     *  if signum == SIGUSR2 
     *     increment i
     *  else if signum == SIGUSR1 
      *    print the number of bytes recieved (NB: 8 bits = 1 byte)
     */
}

int char_to_bin(char c, int pid)
{
  /** 
     *  VARIABLES
     *  
     *  create a variable int itr
     *  int bit_index to loop over each byte
     *
     *  initialise bit_index to 7 ie 0 -> 7 which will make 8 bits
     *  create a while loop to loop bit by bit by decrementing from 7 to 0
     * while(bit_idx >= 0)
     *{
          // initialize itr back to zero
          // conversion
          if ((c >> bit_index) & 1)
              kill(pid, SIGUSR1);
          else
              kill(pid, SIGUSR2);
          while (g_receiver == 0)
          {
             if (itr == 50) // wait for response after count of 50 (any number)
             {
                //print no response from server here and exit
             }
             // increment itr by 1
             usleep(100); // gives enough time for each signal to be processed
          }
          // re-initialize g_receiver back to zero and decrement bit_index by 1
         }
         return (0);
     */
}

int main(int argc, char** argv)
{
   pid_t srv;
   char  *message;

   if (argc != 3)
   {
      ft_printf("Usage = ./bin/minitalk <PID> '\'Message'\'\n");
      exit(EXIT_FAILURE);
   }
   
   srv = ft_atoi(argv[1]);
   message = argv[2];
   while (*message)
      send_char(*message++, srv);
   send_char('\0', srv);
}