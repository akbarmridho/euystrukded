# BNMO Cooking Simulator

## Deskripsi Program

BNMO (dibaca: Binomo) adalah sebuah robot game milik Indra dan Doni. Akhir-akhir ini, Indra baru saja menjalin hubungan
spesial dengan perempuan bernama Siska Kol. Dan dalam dekat waktu, Indra akan mengajak Siska Kol ke rumah untuk makan
malam bersama Doni dan BNMO. Oleh karena itu, Indra meminta bantuan BNMO dan Doni untuk membantu mempersiapkan makan
malam spesial tersebut. Saat itu juga, BNMO langsung tertarik untuk mengerjakan bagian masak karena ia sangat sering
melihat video memasak di aplikasi toktok dan sangat terngiang-ngiang dengan “mari kita cobaaa”.

Namun, ada masalah. BNMO tidak tahu cara memasak dan Doni tidak bisa membantu persiapan karena ada hal lain. BNMO tidak
bisa belajar dari video youcub karena BNMO adalah sebuah komputer sehingga hal yang paling mudah untuk dilakukan adalah
membuatkan program simulasi untuk ditiru BNMO. Oleh karena itu, Doni meminta bantuan kalian untuk membuatkan program
simulasi tersebut.

Alur dan struktur umum program ini dapat diakses melalui dokumen [berikut](CODE_STYLE.md).

## Anggota

1. Eugene Yap Jin Quan (13521074)
2. Wilson Tansil (13521054)
3. Daniel Egiant Sitanggang (13521056)
4. Akbar Maulana Ridho (13521093)
5. Salomo Reinhart Gregory Manalu (13521063)

## Pembagian Tugas

ADT:

1. Wilson: charmachine, wordmachine, stack
2. Egi: food. list_food, list_delivery
3. Eugene: list_food_recipe, recipe, point
4. Salomo: string, notification, simulator
5. Akbar: time, matrix, tree

Services:

1. Eugene: chopper, boiler
2. Salomo: clock, delivery
3. Akbar: notifier, history
4. Wilson: map, mixer
5. Egi: fryer, simulator

Commands:

1. Wilson: config data, buy, catalog
2. Egi: chop, cookbook, delivery
3. Eugene: fry, inventory, mix
4. Akbar: move, redo, undo
5. Salomo: start, exit, wait, main program, boil

## Daftar Fitur dan Status Pengerjaan

ADT

| Nama             | Status  |
|------------------|---------|
| Charmachine      | perfect |
| Wordmachine      | perfect |
| Stack            | perfect |
| Food             | perfect |
| List food        | perfect |
| List delivery    | perfect |
| List food recipe | perfect |
| Recipe           | perfect |
| Point            | perfect |
| String           | perfect |
| Notification     | perfect |
| Simulator        | perfect |
| Time             | perfect |
| Matrix           | perfect |
| Tree             | perfect |

Service

| Nama      | Status |
|-----------|--------|
| Chopper   | -      |
| Boiler    | -      |
| Clock     | -      |
| Delivery  | -      |
| Notifier  | -      |
| History   | -      |
| Map       | -      |
| Mixer     | -      |
| Fryer     | -      |
| Simulator | -      |

Commands

| Nama      | Status |
|-----------|--------|
| Boil      | -      |
| Buy       | -      |
| Catalog   | -      |
| Chop      | -      |
| Cookbook  | -      |
| Delivery  | -      |
| Fry       | -      |
| Inventory | -      |
| Mix       | -      |
| Move      | -      |
| Undo      | -      |
| Redo      | -      |
| Start     | -      |
| Exit      | -      |
| Wait      | -      |

## Setup and Installation

1. Clone repo

```
git clone git@github.com:haiakbar/euystrukded.git
```

atau bila menggunakan https

```
git clone https://github.com/haiakbar/euystrukded.git
```

2. Compile the program

```
todo
```

3. Run the app

```
todo
```

## Branching and Commit Messages

Setiap membuat branch baru harus ambil base dari `main`. Untuk penamaan commit dan branch mengikuti format berikut.
Format branch: `<type>/<title>`
Format commit: `<type>: <subject>`
Penamaan menggunakan kebab case

Untuk type mengikuti semantic berikut.

- `feat`: (new feature for the user, not a new feature for build script)
- `fix`: (bug fix for the user, not a fix to a build script)
- `docs`: (changes to the documentation)
- `style`: (formatting, missing semi colons, etc; no production code change)
- `refactor`: (refactoring production code, eg. renaming a variable)
- `test`: (adding missing tests, refactoring tests; no production code change)
- `chore`: (updating grunt tasks etc; no production code change)

## Pull Request

Untuk melakukan pull request perlu mengikuti flow berikut.

1. Saat selesai mengerjakan task, boleh langsung melakukan PR ke main dengan membuat PR dari branch pengerjaan ke `main`
2. Merge untuk branch `main` boleh dilakukan setelah mendapatkan persetujuan dari minimal satu orang anggota kelompok
   lainnya.
3. Penamaan PR mengikuti format penamaan branch.
4. Pada deskripsi PR mohon menyertakan format berikut.

- What PR About?
- Is there any problems in this PR?

5. Mohon utamakan komunikasi, terutama untuk approval.

## Coding Style

Silakan silakan periksa dan ikuti dokumen [berikut](CODE_STYLE.md).