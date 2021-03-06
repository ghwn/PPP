#include "book.h"

Book::Book(string isbn, string title, string author, string copyright_date)
	: isbn{ isbn }, title{ title }, author{ author }, copyright_date{ copyright_date }, is_checked_out{ false }
{
	if (!is_valid_isbn()) throw Invalid{ "Invalid ISBN" };
	cout << "New book created (ISBN: " << isbn << ')' << endl;
}

bool Book::is_valid_isbn()
{
	vector<string> isbn_parts;
	string part;

	for (int i = 0; i <= isbn.size(); ++i) {
		if (isbn[i] == '-' || isbn[i] == '\0') {
			isbn_parts.push_back(part);
			part = "";
			continue;
		}
		part += isbn[i];
	}

	if (isbn_parts.size() != 4) return false;

	for (int i = 0; i < isbn_parts.size(); ++i) {
		for (int j = 0; j < isbn_parts[i].size(); ++j) {
			char ch = isbn_parts[i][j];
			if ('0' <= ch && ch <= '9');
			else if (i == 3 && (('a' <= ch && ch <= 'z') || 'A' <= ch && ch <= 'Z'));
			else return false;
		}
	}

	return true;
}

Book::Invalid::Invalid(string msg)
	: message{ msg } {}


