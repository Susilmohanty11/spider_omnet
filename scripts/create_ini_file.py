import argparse
import os

# parse arguments
parser = argparse.ArgumentParser(description="Create ini file for the given arguments")
parser.add_argument('--workload-filename', type=str, dest='workload_filename', default='sample_workload.txt')
parser.add_argument('--topo-filename', type=str, help='name of intermediate output file', default='topo.txt')
parser.add_argument('--network-name', type=str, help='name of the output ned filename', default='simpleNet')
parser.add_argument('--ini-filename', type=str, help='name of ini file', default='omnetpp.ini')
args = parser.parse_args()

#
f = open(args.ini_filename, "w+")
f.write("[General]\n\n")
f.write("[Config " +  os.path.basename(args.network_name) + "]\n")
f.write("network = " + os.path.basename(args.network_name) + "\n")
f.write("**.topologyFile = \"" + os.path.basename(args.topo_filename) + "\"\n")
f.write("**.workloadFile = \"" + os.path.basename(args.workload_filename) + "\"\n\n")
f.close()


