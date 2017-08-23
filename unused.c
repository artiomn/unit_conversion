
/*char* bnmalloc(const double n) {
//Выделение памяти для симв. предст-я двоичного числа
	register long int i, in = n;
	register int nm;
	for (i = 10, nm = 1; (in / i) > 0; i *= 10) nm++; //Подсчёт числа цифр
	return((char*)xmalloc(nm*4)); //Каждая дес. цифра представляется 4-мя двоичными
}*/

/*char* rmalloc(long int n) {
//Выделение памяти для римского числа
	register long int i;
	register int nm;
	for (i = 10, nm = 1; (n / i) > 0; i *= 10) nm++; //Подсчёт числа цифр
	i = n / 1000; //Цифр для тысячи
	n %= 1000;
	nm = n / 100; //Цифр для сотен
	i += (nm < 9) ? nm : 2; //Если сотен < 9, то "CCC...", если 9, то "CM"
	n %= 100;
	i += n / 50;
	n %= 50;
	nm = n / 10;
	i += (nm < 4) ? nm : 2;
	n %= 10;
	i += 4; //i + 3, + '/0'
	return((char*)xmalloc(i));
}*/

/* EOF */

