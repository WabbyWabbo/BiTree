#define SIZE 100

int UFSets[SIZE];

void Initial(int S[]) {
	for (int i = 0; i < SIZE; i++)
	{
		S[i] = -1;
	}
}

int Find(int S[], int x) {
	while (S[x] >= 0) {
		x = S[x];
	}
	return x;
}

void Union(int S[], int Root1, int Root2) {
	//Root1 is different from Root2, which represents set's name
	S[Root2] = Root1;//make Root2 to be Root1's child
}