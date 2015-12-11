/**********************************************************************
 *  M�nsterigenk�nning readme.txt
 **********************************************************************/

/**********************************************************************
 *  Empirisk    Fyll i tabellen nedan med riktiga k�rtider i sekunder
 *  analys      n�r det k�nns vettigt att v�nta p� hela ber�kningen.
 *              Ge uppskattningar av k�rtiden i �vriga fall.
 *
 **********************************************************************/
    
      N		brute [s]      sortering [s]
 ----------------------------------
    150		0.008			0.001
    200		0.019			0.003
    300		0.070			0.006
    400		0.155			0.018
    800		1.087			0.065
   1600		8.576			0.208
   3200		68.321			0.704
   6400		548.040			3.119
  12800		4395.437		14.028


/**********************************************************************
 *  Teoretisk   Ge ordo-uttryck f�r v�rstafallstiden f�r programmen som
 *  analys      en funktion av N. Ge en kort motivering.
 *	
 **********************************************************************
 *	Brute force.
 *	Det v�rsta fallet som kan intr�ffa f�r denna algoritm �r att alla 
 *	punkter i filen ligger p� en och samma linje. Detta �r f�r att 
 *	programmet f�rs�ker optimera bort n�gra ber�kningar genom att inte 
 *	loopa genom alla punkter f�r den fj�rde punkten om de tre f�rsta 
 *	f�rsta punkterna inte ligger p� samma linje. Om alla punkter d�remot
 *	ligger p� samma linje, kommer den alltid att beh�va kolla den fj�rde
 *	punkten. Detta g�r att programmet m�ste bes�ka alla kombinationer av 
 *	fyra punkter i filen, allts� nCr(n, 4) bes�k. Alla andra steg i 
 *	programmet, som sortering och inl�sning, tar konstant, linj�r 
 *	nlog(n) tid, s� dessa kan f�rsummas eftersom nCr(n, 4) v�xer mycket
 *	snabbare �n allt annat.
 *	
 *	Algoritmen ligger d�rf�r i O(nCr(n, 4)) i det v�rsta fallet.
 *	
 **********************************************************************
 *	Fast.
 *	Det v�rsta fallet f�r denna algoritm �r, till skillnad fr�n brute force, 
 *	intr�ffar n�r inga punkter ligger p� en linje med 4 eller fler punkter.
 *	D� blir while-loopen som letar efter punkter p� rad linj�r, d� den s�ker
 *	genom N-3 punkter. Den mest kostsammma funktionen i den stora for-loopen blir 
 *	d�rf�r sorteringen av j�mf�relselistan den kostsammaste funktionen, som 
 *	kostar O(nlog(n)) tid. Eftersom den �r i den stora for-loopen som itererar
 *	�ver alla punkter, utf�rs sorteringen n g�nger.
 *	
 *	Algoritmen ligger d�rf�r i O(n�log(n)).
 *	
 **********************************************************************/

Brute:

Sortering:
