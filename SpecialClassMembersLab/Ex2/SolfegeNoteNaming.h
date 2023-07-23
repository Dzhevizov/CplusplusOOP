#pragma once
 
struct SolfegeNoteNaming
{
	NoteName operator()(const std::string& noteText) const
	{
		if (noteText == "Do")
			return 'C';
		if (noteText == "Re")
			return 'D';
		if (noteText == "Mi")
			return 'E';
		if (noteText == "Fa")
			return 'F';
		if (noteText == "Sol")
			return 'G';
		if (noteText == "La")
			return 'A';
		if (noteText == "Si")
			return 'B';

		return '?';
	}
};
