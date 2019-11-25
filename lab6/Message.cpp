/* Message.cpp ---
 * 
 * Filename: Message.cpp
 * Author: Xiaohui Ling / C00212235
 * Description: This is a class implement the Message.h interface.
 */
/* Code: */

#include "Message.h"
#include <iostream>
#include <stdlib.h>

//that constructor will generate random character.
Message::Message()
{
	token = 97+rand()%26;
}

//that method will print out the value of the Message instance object.
void Message::printMsg(){
	std::cout << token;
}

