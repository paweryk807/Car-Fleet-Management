#include"TechnicalExamination.h"

TechnicalExamination::TechnicalExamination(const std::string& date, const std::string& comments, bool result) : comments(comments), result(result)
{
	if (date.length() != 10)
	{
		this->date = "";
		//	std::cout << " Wprowadzono bledna date lub nie wprowadzono jej wcale!  " << std::endl;
	}
	else
	{
		if (!dateValidator(date))
			this->date = "";
		//		std::cout << " Wprowadzono bledna date lub nie wprowadzono jej wcale!  " << std::endl;
		else this->date = date;
	}
}

const bool TechnicalExamination::getResult() const noexcept { return result; }

const string TechnicalExamination::getComments() const noexcept { return comments; }

const string TechnicalExamination::getLastTechnicalExamDate() const noexcept {

	if (!date.empty())
		return date;
	else return "empty";
}

const string TechnicalExamination::getNextTechnicalExamDate() const noexcept {
	if (!date.empty())
	{
		string nextExam = date;
		if (static_cast <int>(nextExam[9]) % 48 == 9)
		{

			if (static_cast <int>(nextExam[8]) % 48 == 9)
			{
				if (static_cast <int>(nextExam[7]) % 48 == 9)
				{
					nextExam[6] += 1;
					nextExam[7] = '0';
					nextExam[8] = '0';
					nextExam[9] = '0';
				}
				else
				{
					nextExam[7] += 1;
					nextExam[8] = '0';
					nextExam[9] = '0';
				}
			}
			else
			{
				nextExam[8] += 1;
				nextExam[9] = '0';
			}
		}
		else
		{
			nextExam[9] += 1;
		}
		return nextExam;
	}
	return "empty";
}

void TechnicalExamination::updateResult(const bool res) noexcept { result = res; }

const bool TechnicalExamination::isValid(const string& dLiczba) const noexcept {
	int	dni = 10 * (date[0] - 48) + date[1] - 48;
	int	miesiac = 10 * (date[3] - 48) + date[4] - 48;
	int	rok = 1000 * (date[6] - 48) + 100 * (date[7] - 48) + 10 * (date[8] - 48) + (date[9] - 48);
	int	dni2 = 10 * (dLiczba[0] - 48) + dLiczba[1] - 48;
	int	miesiac2 = 10 * (dLiczba[3] - 48) + dLiczba[4] - 48;
	int	rok2 = 1000 * (dLiczba[6] - 48) + 100 * (dLiczba[7] - 48) + 10 * (dLiczba[8] - 48) + (dLiczba[9] - 48);
	if (rok2 == rok) {
		if (miesiac2 == miesiac) {
			if (dni2 >= dni) return 1;
			else return 0;// przypadek jak zlecenie jest minimalnie z dnia przegladu 
		}
		else if (miesiac2 > miesiac) return 1; // miesiac jest wyzszy to tez looz 
		else return 0;
	}
	else if (rok2 == rok + 1) {
		if ((miesiac - miesiac2) > 0) return 1;// roznica w datach nie jest wieksza niz rok 
		else if ((miesiac - miesiac2) == 0) {
			if (dni2 <= dni) return 1;  // zawiera sie w przedziale (max dzien przegladu)
			else return 0;
		}
		else return 0;
	}
	else return 0; // data nie jest z zakresu obowiazywania przegladu 

}
	
void TechnicalExamination::updateComments(const string& com) noexcept { comments = com; }

void TechnicalExamination::updateLastTechnicalExamDate(const string& xdate) noexcept {
	if (dateValidator(xdate))
		date = xdate;
	else date = " ";
}

ostream& operator<<(ostream& output, const TechnicalExamination& e) {
	output << "Data przegladu : "	   << e.date << std::endl
		   << "Komentarz : "		   << e.comments << std::endl
		   << "Przeszedl przeglad : "  << utils::toString(e.result) << std::endl;
	return output;
}

TechnicalExamination::~TechnicalExamination() {
}
