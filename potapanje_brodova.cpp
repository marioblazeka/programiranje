// Igra potapanja brodova s inteligencijom računala (na tri različite težine).
// Ako je netko zainteresiran u vezi bilo čega vezano uz ovu igricu, neka mi se javi!
// Kod napisao Mislav Matijević.

// v1.0 20.6.19. igrica napisana (započeta oko 10 sati, završena oko 23 sata)
// v1.1 20.6.19. razne ispravke duboko u noći (dodan limit bodova)
// v1.2 21.6.19. dorađen multiplayer, dodan ovaj popis
// v1.3 21.6.19. ispravke prikaza neprijateljskog polja, dorada smještaja brodova (više se ne smiju dirati)
// v1.4 21.6.19. ispravci za igračeva postavljanja brodova
// v1.5 22.6.19. Razni ispravci. Promijenjen koncept uništavanja brodova; sada igrica zna prepoznati kada je brod uništen. Radilo se do ranih kišnih sati 23.6...
// v1.6 24.6.19. Dodane boje u prikazu (polja i meni). Računalo više ne gađa okolinu uništenih brodova i općenito (puno) bolje "razmišlja".
// v1.7 24.6.19. Uz razne dodatke, tu je i funkcija "unos()" kako igrač više ne bi trebao paziti da ne daj bože upiše slovo umjesto broja i tako sruši program.
// v1.8 25.6.19. Ranih noćnih sati dorađen ispis tijekom igre te popravljene greškice.
// v1.9 20.9.19. Popravljen mali problem nepoznatog uzroka da računalo gađa negativne koordinate.
// v2.0 26.11.19. Popravljeno da kod moda s više igrača tuđe polje bude prikazano pri smještanju brodova; svi moduli pretvoreni u headere.
// v2.1 15.3.20. Minijaturne ispravke - u ovim komentarima ispravljeni brojevi verzija, u meniju broj točan verzije.

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<fstream>
#include<windows.h> // isključivo za mijenjanje boja u konzoli (za ispis polja)

using namespace std;

#include "moduli/deklaracije.h"
#include "moduli/spremanje_postavki.h"
#include "moduli/meni.h"
#include "moduli/igrac_raspored.h"
#include "moduli/kompjuter_raspored.h"
#include "moduli/igra.h"

int main(){
	
	provjera_postavki();
	
	while (true)
	{
		inicijalizacija();
		
		prikaz_meni();		
		
		if (mod==1)
		{
			kompjuter_odredi_sebi();
			
			if (postava == 1) igrac_odredi();
			else kompjuter_odredi_igracu();
			
			singleplayer();
		}
		else
		{
			nazivi_multiplayer();
			
			if (postava == 1) igrac_odredi();
			else kompjuter_odredi_igracima();
			
			multiplayer();
		}
	
	}
	
}
