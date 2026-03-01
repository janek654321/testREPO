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

Skopiuj folder **simulator** na swój komputer. Otwórz wiersz polecenia w tej lokalizacji (najprościej poprzez wpisanie `cmd` w pasku adresu eksploratora plików). Wpisz polecenie `make`, aby skompilować program, lub `make run`, aby skompilować i uruchomić aplikację symulatora.

![](docs/assets/simCompile.png)

## Instalacja i konfiguracja w systemie Linux (testowane na Ubuntu 24.04.04 LTS)

Zainstaluj potrzebne narzędzia i biblioteki graficzne:
```
sudo apt install g++ make libgl1-mesa-dev libx11-dev
```

Aplikację symulatora kompiluj poleceniem `make` (lub `make run`, aby automatycznie uruchomić) z poziomu katalogu **simulator**.


## TODO kompatybilność

[opisać funkcje]

# Programowanie konsoli w Arduino IDE

## Instalacja i konfiguracja środowiska

Pobierz i zainstaluj środowisko [Arduino IDE](https://www.arduino.cc/en/software/), a następnie w **File > Preferences > Additional boards manager URLs** dodaj pakiet:
```
https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
```
![](docs/assets/arduinoIDEpref.png)

Zainstaluj płytki **Raspberry Pi Pico/RP2040/RP2350** z panelu **BOARDS MANAGER**.

![](docs/assets/arduinoIDEboard.png)

Zainstaluj poniższe biblioteki z panelu **LIBRARY MANAGER** wraz ze wszystkimi zależnościami (w przypadku pojawienia się komunikatu **Install library dependencies** kliknij **INSTALL ALL**):

`FastLED` by *Daniel Garcia*<br>
`RTClib` by *Adafruit*<br>
`Adafruit ST7735 and ST7789 Library` by *Adafruit*

![](docs/assets/arduinoIDElib.png)


## Programowanie mikrokontrolera

Otwórz pobrany projekt **TKN_Console** w środowisku Arduino IDE, a następnie z menu **Tools** wybierz płytkę **Waveshare RP2040 Zero**, konfigurację pamięci **Flash Size: 2MB (Sketch: 1792KB, FS: 256KB)** oraz taktowanie procesora **CPU Speed: 125 MHz**. Na tym etapie możliwa jest już kompilacja programu (przycisk **Verify**),

Po podłączeniu kablem USB-C do mikrokontrolera wybierz odpowiedni dostępny **Port** i skompiluj oraz wgraj program za pomocą przycisku **Upload**.

![](docs/assets/arduinoIDEtools.png)


# Dokumentacja i struktura projektu

## Struktura plików

Projekt składa się z plików:

### `TKN_Console.ino`:

Obsługuje konfigurację, przełączanie i pętle główne gier. Zawiera Tworzy potrzebne obiekty globalne, inicjuje moduły, aktywuje timer do 