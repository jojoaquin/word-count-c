# Simple Word Count in C

## Deskripsi

Repositori ini berisi contoh implementasi sederhana algoritma **Word Count** menggunakan bahasa pemrograman C.  
Kode ini memproses sebuah file teks dengan langkah-langkah berikut:

1. **Cleaning**:  
   Membaca file input dan membersihkan teks dengan cara:
   - Mengubah semua huruf menjadi huruf kecil.
   - Menghilangkan tanda baca, hanya menyisakan huruf, angka, dan spasi.
   - Menyimpan hasil teks bersih ke file `cleaned.txt`.

2. **Counting Words**:  
   Membaca file `cleaned.txt`, menghitung frekuensi kemunculan setiap kata, dan menyimpan hasil hitung kata yang sudah diurutkan dari frekuensi terbesar ke terkecil ke dalam file `result.txt`.

---

## Tujuan

Proyek ini bertujuan untuk:
1. Mengimplementasikan algoritma Word Count secara sederhana menggunakan bahasa pemrograman C.
2. Menunjukkan proses dasar pemrosesan teks, seperti normalisasi teks (menjadi huruf kecil) dan pembersihan tanda baca.
3. Menghitung frekuensi kemunculan kata dalam sebuah teks.
4. Implementasi pengurutan data berdasarkan nilai frekuensi.

---

## Struktur File

- `comment_sample.txt` : File input contoh berisi komentar atau teks bebas.
- `cleaned.txt` : File hasil pembersihan teks (semua huruf kecil, tanpa tanda baca).
- `result.txt` : File output yang berisi daftar kata dan jumlah kemunculannya, diurutkan dari yang paling sering muncul.

---

## Cara Menjalankan

1. Siapkan file input dengan nama `comment_sample.txt`.
2. Compile program dengan:
   ```bash
   gcc wordcount.c -o wordcount
3. Jalankan program:
   ```bash
   ./wordcount
4. Cek hasilnya di:
   - cleaned.txt (teks yang sudah dibersihkan)
   - result.txt (hasil penghitungan kata, urut dari yang paling banyak)
