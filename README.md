# Qocoa
Qocoa is a collection of Qt wrappers for OSX's Cocoa widgets.

## Features
- basic fallback to sensible Qt types on non-OSX platforms
- shared class headers which expose no implementation details
- typical Qt signal/slot-based API
- trivial to import into projects (class header/implementation, [single shared global header](https://github.com/mikemcquaid/Qocoa/blob/master/qocoa_mac.h))

## Building
```
git clone git://github.com/mikemcquaid/Qocoa.git
cd Qocoa
qmake # or cmake .
make
```

## Status
I'm not personally working on this any more but will accept pull-requests.

[![Build Status](https://travis-ci.org/MikeMcQuaid/Qocoa.svg?branch=master)](https://travis-ci.org/MikeMcQuaid/Qocoa)

## Usage
For each class you want to use copy the [`qocoa_mac.h`](https://github.com/mikemcquaid/Qocoa/blob/master/qocoa_mac.h), `$CLASS.h`, `$CLASS_mac.*` and `$CLASS_nonmac.*` files into your source tree and add them to your buildsystem. Examples are provided for [CMake](https://github.com/mikemcquaid/Qocoa/blob/master/CMakeLists.txt) and [QMake](https://github.com/mikemcquaid/Qocoa/blob/master/Qocoa.pro).

## Contact
[Mike McQuaid](mailto:mike@mikemcquaid.com)

## License
Qocoa is licensed under the [MIT License](http://en.wikipedia.org/wiki/MIT_License).
The full license text is available in [LICENSE.txt](https://github.com/mikemcquaid/Qocoa/blob/master/LICENSE.txt).

Magnifier and EditClear icons taken from [QtCreator](http://qt-project.org/) and are licensed under the [LGPL](http://www.gnu.org/copyleft/lesser.html).

Other icons are taken from the [Oxygen Project](http://www.oxygen-icons.org/) and are licensed under the [Creative Commons Attribution-ShareAlike 3.0 License](http://creativecommons.org/licenses/by-sa/3.0/).

## Gallery
![Qocoa Gallery](https://github.com/mikemcquaid/Qocoa/raw/master/gallery.png)
