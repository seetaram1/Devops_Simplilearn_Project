#include <stdio.h>
struct placeStringType
{
	int position;
	int NumDigit;
	int value;
};
struct placeStringType placeString[10];
int digit;
static int index;
int NumStrings;
int Set_Thousand_Digit, Set_Tenth_Digit;
//char* conv[10][10];
const char* zero = "zero ";
const char* one = "one ";
const char* two = "two ";
const char* three = "three ";
const char* four = "four ";
const char* five = "five ";
const char* six = "six ";
const char* seven = "seven ";
const char* eight = "eight ";
const char* nine = "nine ";


const char* eleven = "eleven ";
const char* twelve = "twelve ";
const char* thirteen = "thirteen ";
const char* fourteen = "fourteen ";
const char* fifteen = "fifteen ";
const char* sixteen = "sixteen ";
const char* seventeen = "seventeen ";
const char* eighteen = "eighteen ";
const char* ninteen = "ninteen ";

const char* ten = "ten ";
const char* twenty = "twenty ";
const char* thirty = "thirty ";
const char* fourty = "fourty ";
const char* fifty = "fifty ";
const char* sixty = "sixty ";
const char* seventy = "seventy ";
const char* eighty = "eighty ";
const char* ninety = "ninety ";

const char* hundred = "hundred ";
const char* thousand = "thousand ";

char out[100];
int CurrentPos;
void UpdateSingleDigit(int position, int remainder);
void UpdateDoubleDigit(int position, int second, int first);
void updateMainDigit(int position);
void update_String_HolderTable(int place);
int Bytes[10];
int main(void)
{
	int N;
	int Rem;
	int TestCase, T;
	freopen("Simplilearn.txt", "r", stdin);
	freopen("Output.txt", "w+", stdout);
	scanf("%d\n", &T);
	for (TestCase = 1; TestCase <= T; TestCase++)
	{
		scanf("%d\n", &N);
		Set_Thousand_Digit = 0;
		Set_Tenth_Digit = 0;
		digit = 0;
		NumStrings = 0;
		CurrentPos = 0;
		index = 0;
		out[0] = '\0';
		if (N == 0)
		{
			Bytes[digit] = 0;
			update_String_HolderTable(digit);
		}
		while (N)
		{
			Rem = N % 10;
			N = N / 10;

			Bytes[digit] = Rem;
			if(Rem>0)
			update_String_HolderTable(digit);
			digit++;
		}
		for (int i = NumStrings-1; i >= 0; i--)
		{
			if (placeString[i].NumDigit == 1)
			{
				UpdateSingleDigit(placeString[i].position, placeString[i].value);
			}
			else if (placeString[i].NumDigit == 2)
			{
				UpdateDoubleDigit(placeString[i].position, (placeString[i].value) / 10, (placeString[i].value) % 10);
			}
		}
		printf("%s\n", out);
		for (int i = NumStrings; i >= 0; i--)
		{
			placeString[i].position = 0;
			placeString[i].NumDigit = 0;
			placeString[i].value = 0;
			Bytes[i] = 0;
		}
		for (int i = index + 1; i >= 0; i--)
			out[i] = '\0';
	}
	
}
void update_String_HolderTable(int place)
{
	
	switch (place)
	{
	case 0:
		placeString[NumStrings].position = 1;
		placeString[NumStrings].NumDigit = 1;
		placeString[NumStrings].value = Bytes[digit];
		Set_Tenth_Digit = 1;
		NumStrings++;
		break;
	case 1:
		if (Set_Tenth_Digit == 1)
		{
			NumStrings--;
		}
		placeString[NumStrings].position = 1;		
		placeString[NumStrings].NumDigit = 2;
		placeString[NumStrings].value = Bytes[digit] * 10 + Bytes[digit - 1];
		NumStrings++;
		break;
	case 2:
		placeString[NumStrings].position = 3;
		placeString[NumStrings].NumDigit = 1;
		placeString[NumStrings].value = Bytes[digit];
		NumStrings++;
		break;
	case 3:
		placeString[NumStrings].position = 4;
		
		placeString[NumStrings].NumDigit = 1;
		placeString[NumStrings].value = Bytes[digit];
		NumStrings++;
		Set_Thousand_Digit = 1;
		break;
	case 4:
		if (Set_Thousand_Digit == 1)
			NumStrings--;
		placeString[NumStrings].position = 4;		
		placeString[NumStrings].NumDigit = 2;
		placeString[NumStrings].value = Bytes[digit] * 10 + Bytes[digit - 1];
		NumStrings++;
				break;
	default:
		break;
	}	
}
void UpdateDoubleDigit(int position, int second, int first)
{
	int i;
	switch (second)
	{
	case 1:
	{
		switch (first)
		{
		case 1:
			for (i = 0; eleven[i] != '\0'; i++)
			{
				out[index] = eleven[i];
				index++;
			}
			break;
		case 2:
			for (i = 0; twelve[i] != '\0'; i++)
			{
				out[index] = twelve[i];
				index++;
			}
			break;
		case 3:
			for (i = 0; thirteen[i] != '\0'; i++)
			{
				out[index] = thirteen[i];
				index++;
			}
			break;
		case 4:
			for (i = 0; fourteen[i] != '\0'; i++)
			{
				out[index] = fourteen[i];
				index++;
			}
			break;
		case 5:
			for (i = 0; fifteen[i] != '\0'; i++)
			{
				out[index] = fifteen[i];
				index++;
			}
			break;
		case 6:
			for (i = 0; sixteen[i] != '\0'; i++)
			{
				out[index] = sixteen[i];
				index++;
			}
			break;
		case 7:
			for (i = 0; seventeen[i] != '\0'; i++)
			{
				out[index] = seventeen[i];
				index++;
			}
			break;
		case 8:
			for (i = 0; eighteen[i] != '\0'; i++)
			{
				out[index] = eighteen[i];
				index++;
			}
			break;
		case 9:
			for (i = 0; ninteen[i] != '\0'; i++)
			{
				out[index] = ninteen[i];
				index++;
			}
			break;
		case 0:
			for (i = 0; ten[i] != '\0'; i++)
			{
				out[index] = ten[i];
				index++;
			}
			break;

		}
		break;
	}
	case 2:
		for (i = 0; twenty[i] != '\0'; i++)
		{
			out[index] = twenty[i];
			index++;
		}
		UpdateSingleDigit(position, first);
		break;
	case 3:
		for (i = 0; thirty[i] != '\0'; i++)
		{
			out[index] = thirty[i];
			index++;
		}
		UpdateSingleDigit( position, first);
		break;
	case 4:
		for (i = 0; fourty[i] != '\0'; i++)
		{
			out[index] = fourty[i];
			index++;
		}
		UpdateSingleDigit( position, first);
		break;
	case 5:
		for (i = 0; fifty[i] != '\0'; i++)
		{
			out[index] = fifty[i];
			index++;
		}
		UpdateSingleDigit( position, first);
		break;
	case 6:
		for (i = 0; sixty[i] != '\0'; i++)
		{
			out[index] = sixty[i];
			index++;
		}
		UpdateSingleDigit( position, first);
		break;
	case 7:
		for (i = 0; seventy[i] != '\0'; i++)
		{
			out[index] = seventy[i];
			index++;
		}
		UpdateSingleDigit( position, first);
		break;
	case 8:
		for (i = 0; eighty[i] != '\0'; i++)
		{
			out[index] = eighty[i];
			index++;
		}
		UpdateSingleDigit( position, first);
		break;
	case 9:
		for (i = 0; ninety[i] != '\0'; i++)
		{
			out[index] = ninety[i];
			index++;
		}
		UpdateSingleDigit( position, first);
		break;

	}
	if (position > 1)
		updateMainDigit(position);
}
void UpdateSingleDigit(int position, int remainder)
{
	int i;
	switch (remainder)
	{
	case 1:
		for (i = 0; one[i] != '\0'; i++)
		{
			out[index] = one[i];
			index++;
		}

		break;
	case 2:
		for (i = 0; two[i] != '\0'; i++)
		{
			out[index] = two[i];
			index++;
		}
		break;
	case 3:
		for (i = 0; three[i] != '\0'; i++)
		{
			out[index] = three[i];
			index++;
		}
		break;
	case 4:
		for (i = 0; four[i] != '\0'; i++)
		{
			out[index] = four[i];
			index++;
		}
		break;
	case 5:
		for (i = 0; five[i] != '\0'; i++)
		{
			out[index] = five[i];
			index++;
		}
		break;
	case 6:
		for (i = 0; six[i] != '\0'; i++)
		{
			out[index] = six[i];
			index++;
		}
		break;
	case 7:
		for (i = 0; seven[i] != '\0'; i++)
		{
			out[index] = seven[i];
			index++;
		}
		break;
	case 8:
		for (i = 0; eight[i] != '\0'; i++)
		{
			out[index] = eight[i];
			index++;
		}
		break;
	case 9:
		for (i = 0; nine[i] != '\0'; i++)
		{
			out[index] = nine[i];
			index++;
		}
		break;
	case 0:
		for (i = 0; zero[i] != '\0'; i++)
		{
			out[index] = zero[i];
			index++;
		}
		break;
	}
	if (position > 1)
		updateMainDigit(position);	


}

void updateMainDigit(int position)
{
	int i;
	switch (position)
	{
	case 3:
		for (i = 0; hundred[i] != '\0'; i++)
		{
			out[index] = hundred[i];
			index++;
		}
		break;
	case 4:
		for (i = 0; thousand[i] != '\0'; i++)
		{
			out[index] = thousand[i];
			index++;
		}
		break;
	}

}


