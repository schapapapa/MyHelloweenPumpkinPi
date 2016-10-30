Download and Install
WiringPi is maintained under GIT for ease of change tracking, however there is a Plan B if you�re unable to use GIT for whatever reasons (usually your firewall will be blocking you, so do check that first!)

If you do not have GIT installed, then under any of the Debian releases (e.g. Raspbian), you can install it with:

sudo apt-get install git-core
If you get any errors here, make sure your Pi is up to date with the latest versions of Raspbian:

sudo apt-get update
sudo apt-get upgrade
To obtain WiringPi using GIT:

git clone git://git.drogon.net/wiringPi
If you have already used the clone operation for the first time, then

cd wiringPi
git pull origin
Will fetch an updated version then you can re-run the build script below.

To build/install there is a new simplified script:

cd wiringPi
./build
The new build script will compile and install it all for you � it does use the sudo command at one point, so you may wish to inspect the script before running it.