// Einbinden von Bibliotheken
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

/**
* @brief Erstellt 2D Feld mit Punkten aus den Daten in einer Datei;
*
* Öffnung und Bearbeitung einer Datei;
* Speicherung von Koordinaten der Punkten auf 2D Feld in zwei Vectors;
* Überprüfung der Vectors, ob die auf einer aktuellen Position ein Punkt haben;
* Erstellung des 2D Feldes in Console oder in einer Datei mit der Wahlmöglichkeit von User;
*
*/
class Richtungsketten
{
private:
	std::string pathIn;						//Ein Weg zur Datei, die User öffnen möchtet
	std::string pathOut;					//Ein Weg zur Datei, in der User das Ergebnis speichern möchtet
	std::vector<int> CoordinatesX;			//Die Nummern von Spalten mit dem Punkt
	std::vector<int> CoordinatesY;			//Die Nummern von Zeilen mit dem Punkt
	int FieldSizeX = 0;						//Der Breite des 2D Feldes
	int FieldSizeY = 0;						//Die Höhe des 2D Feldes
	int helper = 0;							//Die Hilfsvariable
	std::ifstream fin;						//Ein Objekt von der Klasse ifstream zur Bearbeitung der Datei
	std::ofstream fout;						//Ein Objekt von der Klasse ofstream zur Speicherung der Datei
	char Output;							//Die Kennzeichnung von der Ausgangsquelle
	bool Error = false;						//Die Anwesenheit von Fehlern in der Eingangsdatei
public:
	/**
	* @brief Öffnung der Datei;
	* 
	* Öffnung der gewünschten Datei;
	* Möglichkeit der Fehlerbenachrichtigung;
	* 
	*/
	void FileOpen();
	/**
	* @brief Beendigung des Programmes in der Fall des Fehlers;
	*
	* @pre Mögliche Aufruf in der Funktionen FileOpen, FileHandling, ChoiceOutput;
	*/
	void ErrorCheck();
	/**
	* @brief Bearbeitung der Datei;
	*
	* Überprüfung, ob die Eingangszahlen die Aufgabebedingungen erfüllen;
	* Möglichkeit der Fehlerbenachrichtigung;
	* Übertragung von Daten aus der Datei in int FieldSizeX, FieldSizeY;
	* Befüllung mit den Startkoordinaten der Vectors CoordinatesX und CoordinatesY;
	* Bearbeitung die weiteren Zahlen aus der Eingangsdatei in Koordinaten;
	* Hinzufügung dieser Koordinaten in die Vectors CoordinatesX und CoordinatesY;
	*
	*/
	void FileHandling();
	/**
	* @brief Die Wahl der Ausgangsquelle;
	*
	* Erhalt von User die Ausgangsquelle;
	* Speicherung dieser Ausgangsquelle;
	* Aufruf der Funktion DrawFieldConsole oder DrawFieldFile;
	*
	*/
	void ChoiceOutput();
	/**
	* @brief Erstellung des 2D Feldes in Console;
	*
	* Anruf der booleschen Function VectorCheck für jede Position auf dem Feld ;
	* Zeichnung entweder ' ' oder '*' für jede Position auf dem Feld in Console;
	*
	* @pre Mögliche Aufruf in der Funktion ChoiceOutput;
	* 
	*/
	void DrawFieldConsole();
	/**
	* @brief Erstellung der Datei und Speicherung dort das 2D Feld;
	* 
	* Erstellung der Datei mit der Name, die User eingibt;
	* Anruf der booleschen Function VectorCheck für jede Position auf dem Feld ;
	* Zeichnung entweder ' ' oder '*' für jede Position auf dem Feld in der Datei;
	*
	* @pre Mögliche Aufruf in der Funktion ChoiceOutput;
	* 
	*/
	void DrawFieldFile();
	/**
	* @brief Überprüfung der Vectors, ob die auf einer aktuellen Position ein Punkt haben;
	*
	* Vergleichung für jede Paar der Zahlen (erste Zahl der Paar aus CoordinatesX, zweite aus CoordinatesY)
	* mit dem Paar von aktuellen Coordinates(CX,CY);
	*
	* @param CX ist aktuelle Position auf x(Spalten);
	* @param CY ist aktuelle Position auf y(Zeilen);
	*
	* @return true,wenn es auf der aktuellen Position ein Punkt gibt, sonst false 
	* 
	* @pre Aufruf in der Funktion DrawFieldConsole/DrawFieldFile;
	*
	*/
	bool VectorCheck(int CX, int CY);
};
