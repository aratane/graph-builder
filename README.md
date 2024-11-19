# Program Pembuat Graf dengan Input Dinamis

## 1. Deskripsi Program
Program ini memungkinkan pengguna untuk membuat graf tidak terarah berdasarkan input dinamis, yang mencakup:
- Jumlah simpul
- Jumlah loop
- Jumlah pasang sisi ganda
- Derajat dari setiap simpul
Setelah graf dibentuk, program akan menghasilkan file dalam format DOT yang dapat digunakan untuk menggambar graf secara visual dengan menggunakan Graphviz.

## 2. Prasyarat
Sebelum menjalankan program, pastikan bahwa Anda telah menginstal perangkat lunak berikut:
- C++ Compiler: Program ini ditulis dalam bahasa C++ dan perlu dikompilasi dengan compiler C++ seperti g++.
- Graphviz: Alat untuk menggambar graf berdasarkan file DOT. Anda dapat mengunduhnya di Graphviz.

## 3. Instalasi
### 3.1 Menginstal Graphviz
- Di Linux (Ubuntu/Debian):
```sudo apt-get install graphviz```
- Di macOS (menggunakan Homebrew):
```brew install graphviz```
- Di Windows: Unduh installer Graphviz dari situs resmi Graphviz, lalu ikuti petunjuk instalasi.

### 3.2 Mengompilasi dan Menjalankan Program C++
- Kompilasi Program: Buka terminal atau command prompt dan arahkan ke direktori tempat file program disimpan. Jalankan perintah berikut untuk mengompilasi program:
```g++ -o graph_builder graph_builder.cpp```
- Jalankan Program: Setelah dikompilasi, jalankan program dengan perintah berikut:
```./graph_builder```

## 4. Cara Menggunakan Program
Setelah menjalankan program, Anda akan diminta untuk memasukkan beberapa informasi untuk membangun graf. Berikut adalah urutan input yang akan diminta oleh program:

### 4.1 Input dari Pengguna
- Masukkan jumlah simpul: Program akan meminta Anda memasukkan jumlah simpul dalam graf. (misalnya: 5 simpul).
- Masukkan jumlah loop: Program akan meminta Anda memasukkan berapa banyak simpul yang akan memiliki loop (sisi yang menghubungkan simpul ke dirinya sendiri).
- Masukkan simpul untuk loop: Untuk setiap loop, Anda akan diminta untuk memasukkan nomor simpul yang akan memiliki loop. (misalnya: simpul 1 memiliki loop).
- Masukkan jumlah pasang sisi ganda: Program akan meminta Anda untuk menentukan jumlah pasang sisi ganda. Sisi ganda adalah sisi yang menghubungkan dua simpul yang sama lebih dari sekali.
- Masukkan pasangan sisi ganda: Untuk setiap pasang sisi ganda, Anda akan diminta untuk memasukkan dua simpul yang akan terhubung oleh sisi ganda.
- Masukkan derajat setiap simpul: Program akan meminta Anda untuk memasukkan derajat (jumlah sisi yang terhubung) dari setiap simpul.

### 4.2 Contoh Input
Berikut adalah contoh input yang diminta program:
```Masukkan jumlah simpul: 5
Masukkan jumlah loop: 1
Masukkan simpul untuk loop ke-1: 1
Masukkan jumlah pasang sisi ganda: 2
Masukkan pasangan sisi ganda ke-1 (simpul u dan v): 1 2
Masukkan pasangan sisi ganda ke-2 (simpul u dan v): 2 3
Masukkan derajat setiap simpul (misalnya untuk simpul 1, masukkan derajatnya):
Derajat simpul 1: 3
Derajat simpul 2: 4
Derajat simpul 3: 2
Derajat simpul 4: 2
Derajat simpul 5: 2
```
### 4.3 Output
Setelah input diberikan, program akan menampilkan daftar simpul dan sisi yang terhubung di layar. Berikut adalah contoh output:
```Simpul 1 terhubung ke: 1 2 2 
Simpul 2 terhubung ke: 1 1 3 
Simpul 3 terhubung ke: 2 2 
Simpul 4 terhubung ke: 
Simpul 5 terhubung ke: 
```
Selain itu, program juga akan menghasilkan file graf.dot yang berisi representasi graf dalam format DOT.

## 5. Menghasilkan Visualisasi dengan Graphviz
Setelah program selesai dijalankan, file graf.dot akan dihasilkan. Anda dapat menggunakan Graphviz untuk menghasilkan gambar graf dari file DOT ini.

### 5.1 Menggunakan Graphviz untuk Visualisasi
Untuk menghasilkan visualisasi graf dalam format PNG, jalankan perintah berikut di terminal (pastikan Anda berada di direktori yang sama dengan file graf.dot):

```dot -Tpng graf.dot -o graf.png```

Perintah ini akan menghasilkan file gambar graf.png yang menampilkan visualisasi graf Anda.

### 5.2 Format Output Lainnya
Graphviz juga mendukung berbagai format output lainnya, seperti PDF atau SVG. Berikut adalah contoh perintah untuk menghasilkan file graf.pdf:

```dot -Tpdf graf.dot -o graf.pdf```

## 6. Menyesuaikan Output
Jika Anda ingin menyesuaikan cara graf ditampilkan, Anda bisa mengedit file graf.dot secara manual. Berikut adalah beberapa penyesuaian yang umum dilakukan di file DOT:

Mengubah warna simpul:

```1 [color=red];  // Simpul 1 berwarna merah```

Mengubah bentuk simpul:

```2 [shape=box];  // Simpul 2 berbentuk kotak```

## 7. Contoh File DOT
Berikut adalah contoh file DOT yang dihasilkan oleh program:
```
graph G {
  1 -- 2;
  1 -- 2;
  1 -- 3;
  2 -- 3;
}
```
## 8. Kesalahan Umum dan Pemecahan Masalah
- Kesalahan: Program tidak dapat menemukan Graphviz:
Pastikan Graphviz telah terinstal dan dapat diakses melalui terminal atau command prompt. Jika menggunakan Windows, pastikan Graphviz ditambahkan ke variabel PATH.
- Kesalahan: Tidak dapat mengkompilasi program C++:
Pastikan Anda menggunakan compiler C++ yang benar. Jika Anda menggunakan Linux atau macOS, pastikan g++ telah terinstal.
- Kesalahan: Input yang salah:
Pastikan Anda memasukkan nilai yang benar (misalnya, simpul dan sisi harus dalam rentang yang valid).

## 9. Sumber Daya Tambahan
- Graphviz: https://graphviz.gitlab.io/
- Dokumentasi C++: https://en.cppreference.com/w/

## 10. Lisensi
Program ini dilisensikan di bawah MIT License.

## 11. Kontak
Jika Anda memiliki pertanyaan atau masalah, jangan ragu untuk membuka Issue di halaman GitHub ini.