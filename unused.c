
/*char* bnmalloc(const double n) {
//��������� ������ ��� ����. ������-� ��������� �����
	register long int i, in = n;
	register int nm;
	for (i = 10, nm = 1; (in / i) > 0; i *= 10) nm++; //����ޣ� ����� ����
	return((char*)xmalloc(nm*4)); //������ ���. ����� �������������� 4-�� ���������
}*/

/*char* rmalloc(long int n) {
//��������� ������ ��� �������� �����
	register long int i;
	register int nm;
	for (i = 10, nm = 1; (n / i) > 0; i *= 10) nm++; //����ޣ� ����� ����
	i = n / 1000; //���� ��� ������
	n %= 1000;
	nm = n / 100; //���� ��� �����
	i += (nm < 9) ? nm : 2; //���� ����� < 9, �� "CCC...", ���� 9, �� "CM"
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

