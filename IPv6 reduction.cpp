#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

int main() {
	
	string IP, IPv6, sustraer4, sustraer1;
	int acum=0, cantidad0=0, entero=0;
	int  posicion=0;
	
	cout << "Ingrese la dirección IPv6 para su reducción: " << endl;
	cin >> IP;
	
	
	for (unsigned int i=0; i<IP.length(); i=i+5) {
		
		acum=0;
		sustraer4 = IP.substr(i,4);
		/*		cout << "Sustraer: " << sustraer4 <<endl;*/
		
		for (int j=0;j<4;j++) {
			
			sustraer1 = IP.substr(i+j,1);
			entero = stoi(sustraer1);
			
	/*		if (isalpha(entero)!=0) {*/
				
				acum = acum + entero;
				if (entero != 0) {
					cantidad0=0;
					IPv6 = IPv6 + IP.substr(i+j,4-j) + ":";
/*					cout <<":";*/
					break;
				}	
/*			}*/
		}
		
		if (acum==0) {
			IPv6 = IPv6 + "0:";
			cantidad0++;
			continue;
		}
		
/*		IPv6 = IPv6 + ":";*/
		
	}

	
	cout << "IPV6antes: " << IPv6 << endl;
	if (cantidad0>1) {
		posicion = IPv6.find("0:0:");
		cout << "posicion "<< posicion <<endl <<endl;
/*		IPv6= IPv6 + (IPv6.replace(posicion,cantidad0*2,"::"));*/
		IPv6.replace(posicion,cantidad0*2,"::");
	}
	cout << "IPV6: " << IPv6 << endl;
	//	IP.find("0000:0000:0000:0000:0000:0000:0000:0000") << endl
	
	system ("pause");
	return 0;
} 


