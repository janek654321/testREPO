# O projekcie
Lorem ipsum

# Symulator

Gry na konsolę testować można w dedykowanym symulatorze (zaimplementowana obsługa wyświetlacza matrycowego oraz przycisków). Obsługiwany jest w systemach operacyjnych Windows oraz Linux.

![](docs/assets/simWin.png)

## Instalacja i konfiguracja w systemie Windows (testowane na Windows 11)

### Pobierz i zainstaluj kompilator `g++` oraz narzędzie `make`

Najłatwiej jest do tego użyć programu [MSYS2](https://www.msys2.org/). Po instalacji z domyślnymi parametrami, pobierz wymagane pakiety, wpisując w konsoli MSYS2 UCRT64:
```
pacman -S mingw-w64-ucrt-x86_64-gcc
```
a następnie:
```
pacman -S make
```

Zaktualizuj zmienną środowiskową PATH o ścieżki do wymaganych programów zgodnie z instrukcją:

**WIN+R > SystemPropertiesAdvanced.exe > Zmienne środowiskowe > Path > Edytuj > Nowy**

Wpisz: **C:\msys64\usr\bin** oraz **C:\msys64\ucrt64\bin**

![](docs/assets/gppMakeEnv.png)

Na koniec zweryfikuj poprawne działanie narzędzi, wpisując w systemowym wierszu polecenia (CMD):

```
g++ --version
```
```
make --version
```
![](docs/assets/gppVer.png)

### Kompilacja i uruchomienie gry

Przenieś na swój komputer folder **simulator**, otwórz wiersz polecenia i przejdź do ścieżki tego folderu (najłatwiej poprzez wpisanie `cmd` w pasku adresu eksploratora plików z otwartym katalogiem symulatora). Wpisz `make` aby skompilować program lub `make run` aby skompilować i uruchomić aplikację symulatora.

![](docs/assets/simCompile.png)

## Instalacja i konfiguracja w systemie Linux (testowane na Ubuntu 24.04.04 LTS)

Zainstaluj biblioteki graficzne:
```bash
sudo apt install libgl1-mesa-dev libx11-dev
```