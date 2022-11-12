### Install

```js
sudo apt install g++ cmake make libasio-dev
```

### Clone pr github

```js
git clone https://github.com/CrowCpp/Crow
```

### Navigate to Crow

```js
cd Crow
```

### Create folder build

```js
mkdir build
```

### Create environment

```js
cmake -B build .
```

### ### Navigate to build

```js
cd build
```

### Paste terminal

```js
cmake .. -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF
```

```js
sudo cmake install
```
### Run 
```js
g++ main.cpp -lpthread
```
