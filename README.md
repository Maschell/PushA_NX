# PUSH A for Switch

Based on: https://github.com/vgmoose/sdl-hello-world

Back to the roots. Back in 2008 I started with writing homebrew on Wii. The first "game" I created was "Push A".  
Now, almost 10 years later, I quickly wrote a new version for the Switch.  

Have fun!  

Huge thanks to vgmoose, based on his examples!.  

### Compiling
#### For Switch
Clone and setup libtransistor, for more detail [see this post](https://reswitchedweekly.github.io/Development-Setup/).
```
git clone --recursive https://github.com/reswitched/libtransistor.git
cd libtransistor
make
cd ..
```

Setup sdl-libtransistor and export an environment variable pointing to your libtransistor build:
```
export LIBTRANSISTOR_HOME=/opt/libtransistor
git clone https://github.com/reswitched/sdl-libtransistor.git
cd sdl-libtransistor
make -f switch.mk
cd ..
```

Compile with make:
```
make
```

### Running
See [these instructions](https://gbatemp.net/threads/switch-hacking-101-how-to-launch-the-homebrew-menu-on-all-fw.504012/) on how to use Fusee Gelee to run this homebrew on most Switches as of this time of writing (22/07/2018).
