import matplotlib.animation as animation
import matplotlib.pyplot as mygraph
bg = mygraph.figure()
def draw(i):
	cox = []
	coy = []
	txtdata = open('network-test-latency.txt','r').read()
	listdata = txtdata.split('\n')
	mygraph.xlabel('DNS Names')
	mygraph.ylabel('Average RTT')
	mygraph.title('Graph of DNS names vs average RTT')
	for line in listdata:
		if len(line) > 1 :
			xco, yco = line.split(' ')
			cox.append(xco)
			coy.append(float(yco))
	mygraph.ylabel('Average RTT')
	mygraph.title('Graph of DNS names vs average RTT')
	mygraph.plot(cox,coy)
xyz = animation.FuncAnimation(bg,draw,interval=2000)
mygraph.show()
