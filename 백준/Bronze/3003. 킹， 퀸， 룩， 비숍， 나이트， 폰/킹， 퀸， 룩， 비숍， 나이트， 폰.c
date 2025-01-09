#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int King = 0;
	int Queen = 0;
	int Rook = 0;
	int Bishop = 0;
	int Knight = 0;
	int Pawn = 0;
	scanf("%d %d %d %d %d %d", &King, &Queen, &Rook, &Bishop, &Knight, &Pawn);

	if (King != 1)
	{
		King = 1 - King;
	}
	else
		King = 0;
	if (Queen != 1)
	{
		Queen = 1 - Queen;
	}
	else
		Queen = 0;
	if (Rook != 2)
	{
		Rook = 2 - Rook;
	}
	else
		Rook = 0;
	if (Bishop != 2)
	{
		Bishop = 2 - Bishop;
	}
	else
		Bishop = 0;
	if (Knight != 2)
	{
		Knight = 2 - Knight;
	}
	else
		Knight = 0;
	if (Pawn != 8)
	{
		Pawn = 8 - Pawn;
	}
	else
		Pawn = 0;

	printf("%d %d %d %d %d %d", King, Queen, Rook, Bishop, Knight, Pawn);
}