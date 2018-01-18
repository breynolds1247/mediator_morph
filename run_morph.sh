
hostname
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh
lsetup root
cd /afs/cern.ch/user/b/boveia/work/mediator-morph
python morph.py $1 $2
