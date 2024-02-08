/**
 * Each Ethernet network card is characterized by a unique 48-bit identifier, which is called Medium Access Control (MAC) address. Typically, 
 * the MAC address is represented in hex form. To find the type of the address, we check the value of the first octet at the left. If it is 
 * even, the address type is unicast. If it is odd, the type is multicast. If all octets are 0xFF, the type is broadcast. For example:
 * 
 * 
 * a. The FF:FF:FF:FF:FF:FF address is broadcast. 
 * b. The 18:20:3F:20:AB:11 address is unicast because 18 is even. 
 * c. The A3:3F:40:A2:C3:42 address is multicast because A3 is odd.
 * 
 * 
 * Write a program that reads a MAC address and displays its type. Assume that the user enters the MAC address in x:x:x:x:x:x form, where each x is a hex number.
 * 
*/