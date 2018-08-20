all:
	+ $(MAKE) -C ./src
	+ @echo Built src.
	+ $(MAKE) -C ./tests
	+ @echo Built tests.
	+ $(MAKE) -C ./examples
	+ @echo Built examples.

clean:
	cd ./src && $(MAKE) clean
	cd ./tests && $(MAKE) clean
	cd ./examples && $(MAKE) clean
