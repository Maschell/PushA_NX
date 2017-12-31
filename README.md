# PUSH A for Switch
  
Based on: https://github.com/vgmoose/sdl-hello-world

Back to the roots. Back in 2008 I started with writing homebrew on Wii. The first "game" I created was "Push A".  
Now, almost 10 years later, I quickly wrote a new version for the Switch.  

Maybe only works with detached Joy-Cons.  
  
Have fun!  
  
Huge thanks to vgmoose, based on his examples!.  

### Compiling
#### For Switch
Clone and setup libtransistor, for more detail [see this post](https://reswitchedweekly.github.io/Development-Setup/).
```
git clone --recursive -b graphics-experimental-fs https://github.com/reswitched/libtransistor.git
cd libtransistor
make
cd ..
```

Then export an environment variable pointing to your libtransistor build, and run `make`:
```
export LIBTRANSISTOR_HOME=./libtransistor
make
```

### Running
The below instructions are for 3.0.0, written on 12/30/2017:

Build ace_loader in `./projects/ace_loader` of libtransistor, by running `make`

Copy the built `ace.nro` into Pegaswitch's `nros` directory (overwrite the existing one)

Run [Pegaswitch](https://github.com/reswitched/pegaswitch) on your computer, and set your Switch's DNS server to your computer's.

Once pegaswitch connects, run ace_loader with `runnro nros/ace.nro`. If this is your first time running Pegaswitch, use `evalfile usefulscripts/SetupNew.js` first.

If successful, the Switch should be back at the Wifi menu, and frozen. From here:
```
nc <SWITCHIP> 2991 < hello.nro
```

Where `<SWITCHIP>` is the IP of your switch.

See [here](https://github.com/reswitched/pegaswitch#usage) for more on Pegaswitch, and [here](https://github.com/reswitched/libtransistor) on ace_loader.

[See this post](https://reswitchedweekly.github.io/Development-Setup/) for more troubleshooting
