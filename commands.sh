mkdir -p dataLikeHists_J7503_1GeVBins_fixed_morphed/
mkdir -p dataLikeHists_J7506_1GeVBins_fixed_morphed/
mkdir -p dataLikeHists_J10006_1GeVBins_fixed_morphed/
echo "#!/bin/bash " > bjob_7503_0.20.sh
echo "#!/bin/bash " > bjob_7503_0.30.sh
echo "#!/bin/bash " > bjob_7503_0.15.sh
echo "#!/bin/bash " > bjob_7503_0.10.sh
echo "#!/bin/bash " > bjob_7503_0.05.sh
echo "#!/bin/bash " > bjob_7503_0.40.sh
echo "#!/bin/bash  " > bjob_10006_0.20.sh
echo "#!/bin/bash  " > bjob_10006_0.30.sh
echo "#!/bin/bash  " > bjob_10006_0.15.sh
echo "#!/bin/bash  " > bjob_10006_0.10.sh
echo "#!/bin/bash  " > bjob_10006_0.05.sh
echo "#!/bin/bash  " > bjob_10006_0.40.sh
echo "#!/bin/bash " > bjob_7506_0.20.sh
echo "#!/bin/bash " > bjob_7506_0.30.sh
echo "#!/bin/bash " > bjob_7506_0.15.sh
echo "#!/bin/bash " > bjob_7506_0.10.sh
echo "#!/bin/bash " > bjob_7506_0.05.sh
echo "#!/bin/bash " > bjob_7506_0.40.sh

echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_7503_0.20.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_7503_0.30.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_7503_0.15.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_7503_0.10.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_7503_0.05.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_7503_0.40.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_10006_0.20.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_10006_0.30.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_10006_0.15.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_10006_0.10.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_10006_0.05.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_10006_0.40.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_7506_0.20.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_7506_0.30.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_7506_0.15.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_7506_0.10.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_7506_0.05.sh
echo "cd /afs/cern.ch/user/b/boveia/work/mediator-morph" >> bjob_7506_0.40.sh

echo "./run_morph.sh 7503 0.20 >& log_7503_0.20.log" >> bjob_7503_0.20.sh
echo "./run_morph.sh 7503 0.30 >& log_7503_0.30.log" >> bjob_7503_0.30.sh
echo "./run_morph.sh 7503 0.15 >& log_7503_0.15.log" >> bjob_7503_0.15.sh
echo "./run_morph.sh 7503 0.10 >& log_7503_0.10.log" >> bjob_7503_0.10.sh
echo "./run_morph.sh 7503 0.05 >& log_7503_0.05.log" >> bjob_7503_0.05.sh
echo "./run_morph.sh 7503 0.40 >& log_7503_0.40.log" >> bjob_7503_0.40.sh
echo "./run_morph.sh  10006 0.20 >& log_ 10006_0.20.log" >> bjob_10006_0.20.sh
echo "./run_morph.sh 10006 0.30 >& log_10006_0.30.log" >> bjob_10006_0.30.sh
echo "./run_morph.sh 10006 0.15 >& log_10006_0.15.log" >> bjob_10006_0.15.sh
echo "./run_morph.sh 10006 0.10 >& log_10006_0.10.log" >> bjob_10006_0.10.sh
echo "./run_morph.sh 10006 0.05 >& log_10006_0.05.log" >> bjob_10006_0.05.sh
echo "./run_morph.sh 10006 0.40 >& log_10006_0.40.log" >> bjob_10006_0.40.sh
echo "./run_morph.sh 7506 0.20 >& log_7506_0.20.log" >> bjob_7506_0.20.sh
echo "./run_morph.sh 7506 0.30 >& log_7506_0.30.log" >> bjob_7506_0.30.sh
echo "./run_morph.sh 7506 0.15 >& log_7506_0.15.log" >> bjob_7506_0.15.sh
echo "./run_morph.sh 7506 0.10 >& log_7506_0.10.log" >> bjob_7506_0.10.sh
echo "./run_morph.sh 7506 0.05 >& log_7506_0.05.log" >> bjob_7506_0.05.sh
echo "./run_morph.sh 7506 0.40 >& log_7506_0.40.log" >> bjob_7506_0.40.sh

chmod u+x bjob*.sh

bsub -q 8nh bjob_7503_0.20.sh
bsub -q 8nh bjob_7503_0.30.sh
bsub -q 8nh bjob_7503_0.15.sh
bsub -q 8nh bjob_7503_0.10.sh
bsub -q 8nh bjob_7503_0.05.sh
bsub -q 8nh bjob_7503_0.40.sh
bsub -q 8nh bjob_10006_0.20.sh
bsub -q 8nh bjob_10006_0.30.sh
bsub -q 8nh bjob_10006_0.15.sh
bsub -q 8nh bjob_10006_0.10.sh
bsub -q 8nh bjob_10006_0.05.sh
bsub -q 8nh bjob_10006_0.40.sh
bsub -q 8nh bjob_7506_0.20.sh
bsub -q 8nh bjob_7506_0.30.sh
bsub -q 8nh bjob_7506_0.15.sh
bsub -q 8nh bjob_7506_0.10.sh
bsub -q 8nh bjob_7506_0.05.sh
bsub -q 8nh bjob_7506_0.40.sh
