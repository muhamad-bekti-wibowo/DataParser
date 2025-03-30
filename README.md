# DataParser.h - Library Parsing String untuk Arduino

![Arduino](https://img.shields.io/badge/Arduino-Compatible-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

## 📌 Deskripsi
**DataParser.h** adalah library untuk **Arduino** yang digunakan untuk **memecah (parsing) string** berdasarkan karakter pemisah. Library ini sangat berguna untuk memproses data dari komunikasi serial, sensor, atau format data berbasis CSV.

## ✨ Fitur Utama
- **Parsing string dengan karakter pemisah** (separator) menjadi array string.
- **Membatasi jumlah elemen** dalam array output untuk mencegah overflow.
- **Menghitung jumlah pemisah** dalam string input.
- **Debugging opsional** dengan output Serial (jika `SerialDataParser` diaktifkan).

## 📥 Instalasi
1. **Download** file `DataParser.h`.
2. **Tambahkan** ke dalam folder proyek Arduino.
3. **Masukkan** dalam kode Arduino dengan:
   ```cpp
   #include "DataParser.h"
   ```

## 🚀 Cara Penggunaan
### 1️⃣ Parsing String dengan Separator
Misalkan kita memiliki **string input**:
```cpp
#include "DataParser.h"

void setup() {
  Serial.begin(9600);
  String data = "12.5,45.3,67.8,90.1";
  String hasil[10];
  int jumlahData;
  
  DataParser::parse(data, hasil, ',', jumlahData);

  for (int i = 0; i < jumlahData; i++) {
    Serial.println(hasil[i]);
  }
}

void loop() {}
```
**Output Serial:**
```
12.5  
45.3  
67.8  
90.1  
```

### 2️⃣ Parsing dengan Batasan Jumlah Elemen
Jika ingin membatasi jumlah data yang diparsing:
```cpp
int maxData = 3;
DataParser::parse(data, hasil, ',', jumlahData, maxData);
```
Hanya **3 elemen pertama** yang akan diambil.

### 3️⃣ Menghitung Jumlah Separator dalam String
```cpp
int jumlahSeparator = DataParser::count(data, ',');
Serial.println(jumlahSeparator);
```

## ⚙️ API Referensi
### `parse(String input, String *outputData, char separator, int &stringCount)`
- **Memecah string input** berdasarkan separator.
- `outputData` berisi hasil parsing.
- `stringCount` menyimpan jumlah data yang dipisahkan.

### `parse(String input, String *outputData, char separator, int &stringCount, int maxStrings)`
- Sama seperti fungsi sebelumnya, tetapi dengan **batas maksimal elemen (`maxStrings`)** untuk mencegah overflow.

### `count(String input, char separator)`
- **Menghitung jumlah separator** dalam string input.

## 📜 Lisensi
Library ini dirilis di bawah **MIT License**.

---
💡 **Kontribusi**: Silakan buat **pull request** atau **issue** jika ada perbaikan atau fitur tambahan yang ingin diusulkan.

📧 **Kontak**: Jika ada pertanyaan, hubungi **Muhamad Bekti Wibowo**.

🚀 Selamat Coding! 🎯

