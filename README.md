# A

1.Install tensorflow for python 3 https://www.tensorflow.org/install/pip

2.Activate the created virtual environment 

	source ./venv/bin/activate

3.Nagigate to project A folder

4.Build 
	
	cmake clean
	
	cmake --build . --target Demo -- -j 2
	
5.Run 

	./Demo --learning_rate 0.02 --graph 2

output should be :

    start
    Flags Set
    0.02
    gcn
    2
    Done


