all:
	+ $(MAKE) -C ./src
	+ $(MAKE) -C ./tests

clean:
	cd ./src && $(MAKE) clean
	cd ./tests && $(MAKE) clean
