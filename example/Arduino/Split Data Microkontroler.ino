#include "DataParser.h"

void setup()
{
  Serial.begin(9600);

  // Contoh string yang akan diparsing (misalnya dari sensor atau komunikasi)
  String dataString = "23.5,76.8,1013.2,ON";

  // Siapkan array untuk menampung hasil parsing
  String output[10];    // Array dengan ukuran maksimum 10 elemen
  int jumlahString = 0; // Variabel untuk menyimpan jumlah string hasil parsing

  // Panggil fungsi parse dari DataParser
  DataParser::parse(dataString, output, ',', jumlahString);

  // Tampilkan hasil
  Serial.println("Hasil parsing:");
  for (int i = 0; i < jumlahString; i++)
  {
    Serial.print("Data ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(output[i]);
  }
  // Example string to be parsed (e.g., from sensors or communication)
  String data = "23.5,76.8,1013.2,ON,67.2,125";
  
  // Prepare array to store parsing results

  int stringCount = 0;           // Variable to store the number of parsed strings
  int maxStrings = DataParser::count(data, ',') + 1; // Maximum number of strings to parse (array size)
  String outputData[maxStrings]; // Array with maximum size in (maxStrings)
  // Call parse function from DataParser
  DataParser::parse(data, outputData, ',', stringCount, maxStrings);

  // Display results
  Serial.println("Parsing results:");
  Serial.print("Number of strings: ");
  Serial.println(stringCount);

  for (int i = 0; i < stringCount; i++)
  {
    Serial.print("Data ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(outputData[i]);
  }
}

void loop()
{
  // Main loop code
}
