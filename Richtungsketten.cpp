#include "Richtungsketten.h"

void Richtungsketten::FileOpen()
{
	std::cout << "Die Name der Datei, die Sie lesen möchten:";
	std::cin >> pathIn;
	fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);		//Einbinden der Bibliothek zur Beschreibung der Fehler
	try
	{
		fin.open(pathIn);
	}
	catch (const std::ifstream::failure& ex)
	{
		std::cout << ex.what() << std::endl;							//Zeigt die Information über der Fehler
		std::cout << ex.code() << std::endl;
		Error = true;
	}
	if (Error != true && fin.peek() == EOF) {							//Wenn erstes Symbol ist das Endessymbol
		std::cout << "Die Datei ist leer" << std::endl;
		Error = true;
	}
	ErrorCheck();
}

void Richtungsketten::ErrorCheck()
{
	if (Error)
	{
		exit(0);
	}
}

void Richtungsketten::FileHandling()
{
	while (!fin.eof())
	{
		if (FieldSizeX == 0) {											//Erste Zahl in der Datei ist die Breite des Feldes
			fin >> helper;
			if (helper > 0) FieldSizeX = helper;						//Die Zahl muss positiv sein
			else
			{
				std::cout << "Der Breite kann nicht negativ oder gleich Null sein";
				Error = true;
				break;
			}
		}
		if (FieldSizeY == 0) {											//Zweite Zahl in der Datei ist die Höhe
			fin >> helper;
			if (helper > 0) FieldSizeY = helper;
			else
			{
				std::cout << "Die Höhe kann nicht negativ oder gleich Null sein";
				Error = true;
				break;
			}
		}
		if (CoordinatesX.empty()) {										//Dritte ist die Startposition auf x(Spalte)
			fin >> helper;
			if (helper > 0) CoordinatesX.push_back(helper);
			else
			{
				std::cout << "Die Punktkoordinaten können nicht negativ sein";
				Error = true;
				break;
			}
		}
		if (CoordinatesY.empty()) {										//Vierte ist die Startposition auf y(Zeile)
			fin >> helper;
			if (helper > 0) CoordinatesY.push_back(helper);
			else
			{
				std::cout << "Die Punktkoordinaten können nicht negativ sein";
				Error = true;
				break;
			}
		}
		fin >> helper;
		switch (helper)													//Weitere Befüllung der Vectors den Koordinaten
		{
		case 1:															//1: das Kästchen links
			CoordinatesX.push_back(CoordinatesX.back() - 1);			//nimmt letzte KoordinateX und addiert (-1)
			CoordinatesY.push_back(CoordinatesY.back());
			break;
		case 2:															//2: links unten
			CoordinatesX.push_back(CoordinatesX.back() - 1);
			CoordinatesY.push_back(CoordinatesY.back() - 1);
			break;
		case 3:															//3: unten
			CoordinatesX.push_back(CoordinatesX.back());
			CoordinatesY.push_back(CoordinatesY.back() - 1);
			break;
		case 4:															//4: unten rechts
			CoordinatesX.push_back(CoordinatesX.back() + 1);
			CoordinatesY.push_back(CoordinatesY.back() - 1);
			break;

		case 5:															//5: rechts
			CoordinatesX.push_back(CoordinatesX.back() + 1);
			CoordinatesY.push_back(CoordinatesY.back());
			break;
		case 6:															//6: oben rechts
			CoordinatesX.push_back(CoordinatesX.back() + 1);
			CoordinatesY.push_back(CoordinatesY.back() + 1);
			break;
		case 7:															//7: oben
			CoordinatesX.push_back(CoordinatesX.back());
			CoordinatesY.push_back(CoordinatesY.back() + 1);
			break;
		case 8:															//8: oben links
			CoordinatesX.push_back(CoordinatesX.back() - 1);
			CoordinatesY.push_back(CoordinatesY.back() + 1);
			break;
		default:														//Benachrichtigung, wenn die Zahl nicht im Intervall [1; 8] liegt
			std::cout << helper << " ist nicht im Interval von 1 bis 8" << std::endl;
			break;
		}
	}
	fin.close();
	ErrorCheck();
}

void Richtungsketten::ChoiceOutput()
{
	std::cout << "Möchten Sie das Ergebnis in Console oder in der Datei sehen?" << std::endl;
	std::cout << "Schreiben Sie entweder 'C' für Console oder 'D' für Datei:";
	std::cin >> Output;
	if (Output == 'C') DrawFieldConsole();
	if (Output == 'D') DrawFieldFile();
	if (Output != 'C' && Output != 'D') Error = true;
	ErrorCheck();
}

void Richtungsketten::DrawFieldConsole()
{
	for (int i = FieldSizeY; i > 0 ; i--)								//Man beginnt von oben, es ist bequemer
	{
		for (int j = 1; j < FieldSizeX+1; j++)
		{
			if (VectorCheck(j, i)) std::cout << "*";
			else std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void Richtungsketten::DrawFieldFile()
{
	std::cout << "Die Name der Datei, in der Sie die Ausgabe speichern möchten:";
	std::cin >> pathOut;
	fout.open(pathOut);
	for (int i = FieldSizeY; i > 0; i--)
	{
		for (int j = 1; j < FieldSizeX + 1; j++)
		{
			if (VectorCheck(j, i)) fout << "*";
			else fout << " ";
		}
		fout << std::endl;
	}
	fout.close();
}

bool Richtungsketten::VectorCheck(int CX, int CY)
{
	for (int i = 0; i < CoordinatesX.size(); i++)						//Die Größen von CoordinatesX und CoordinatesY sind gleiche
	{
		if (CoordinatesX[i] == CX && CoordinatesY[i] == CY) {
			return true;
		}
	}
	return false;
}


