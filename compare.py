
import array
import ROOT
import re

def rebin_unitGeV_histogram(histogram):
    # rebins TH1 'histogram' (with 1 GeV bins) into the standard binning
    binning = [x/1. for x in [0, 362, 381, 400, 420, 441, 462, 484, 507, 531, 555, 580, 606, 633, 661, 690, 720, 751, 784, 818, 853, 889, 927, 966, 1007, 1049, 1093, 1139, 1186, 1235, 1286, 1339, 1394, 1451, 1511, 1573, 1637, 1704, 1773, 1845, 1920, 1998, 2079, 2163, 2251, 2342, 2437, 2536, 2639, 2746, 2857, 2973, 3094, 3220, 3351, 3487, 3629, 3776, 3929, 4088, 4254, 4427, 4607, 4794, 4989, 5191, 5402, 5621, 5849, 6086, 6333, 6590, 6857, 7135, 7425, 7726, 8040, 8366, 8706, 9059, 9427, 9810, 10208, 10622, 11053, 11502, 11969, 12455, 12960, 13486, 14000]]
    numberOfBins = len(binning)-1
    rebinnedHist = histogram.Rebin(numberOfBins, "rebinned", array.array('d',binning));
    return rebinnedHist

sources=["dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.35_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.35_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.45_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.45_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.45_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.45_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.45_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.55_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.55_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.55_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.55_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.55_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.65_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.65_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.65_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.65_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.65_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.65_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.75_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.75_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.75_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.75_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.75_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.75_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.85_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.85_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.85_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.85_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.85_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.95_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.95_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.95_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.95_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.95_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m0.95_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m1.00_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m1.00_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m1.00_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m1.05_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m1.05_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m1.15_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m1.50_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m1.50_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m1.50_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m1.70_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m1.70_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m1.70_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m1.70_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m2.00_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m2.00_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m2.00_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed/dataLikeHistograms.m2.00_g0.40.root"]
    

morphed=["dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.55_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.55_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.55_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.55_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.55_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.5_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.5_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.5_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.5_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.5_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.65_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.65_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.65_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.65_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.65_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.65_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.6_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.6_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.6_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.6_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.6_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.725_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.725_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.725_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.725_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.725_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.725_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.75_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.75_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.75_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.75_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.75_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.75_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.7_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.7_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.7_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.7_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.7_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.7_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.85_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.85_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.85_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.85_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.85_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.85_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.8_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.8_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.8_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.8_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.8_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.8_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.95_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.95_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.95_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.95_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.95_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.95_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.9_g0.05.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.9_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.9_g0.15.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.9_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.9_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m0.9_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.05_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.05_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.05_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.05_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.0_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.0_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.0_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.0_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.15_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.15_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.15_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.15_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.1_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.1_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.1_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.1_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.25_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.25_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.25_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.25_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.2_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.2_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.2_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.2_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.35_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.35_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.35_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.35_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.3_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.3_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.3_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.3_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.45_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.45_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.45_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.45_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.4_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.4_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.4_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.4_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.5_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.5_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.5_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.5_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.6_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.6_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.6_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.6_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.7_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.7_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.7_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.7_g0.40.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.8_g0.10.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.8_g0.20.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.8_g0.30.root",
         "dataLikeHists_J10006_1GeVBins_fixed_morphed/dataLikeHistograms.m1.8_g0.40.root"]

h1d = ROOT.TH2D("h1","",200,0,2000,20,0.1,10000)
h1d.Draw()
ROOT.gPad.SetLogy(1)

source_h = []

for fname in sources:
    f=ROOT.TFile.Open("samples/"+fname,"READ")
    if not 'g0.40' in fname:
        continue
    
    m = re.search('dataLikeHistograms\.m([0-9\.]*)_g([0-9\.]*)\.', fname )
    mass = m.group(1)
    coupling = m.group(2)

    hname = "mjj_Scaled_m%s_g%s_1fb_Nominal" % (mass,coupling)
    print hname
    h = f.Get(hname)
    if h:
        print h.Integral()
        h = rebin_unitGeV_histogram(h)
        h.SetMarkerColor(ROOT.kBlack)
        source_h.append(h.Clone(hname))

morph_h = []
for fname in morphed:
    f=ROOT.TFile.Open("samples/"+fname,"READ")
    if not 'g0.40' in fname:
        continue
    
    m = re.search('dataLikeHistograms\.m([0-9\.]*)_g([0-9\.]*)\.', fname )
    mass = m.group(1)
    coupling = m.group(2)

    hname = "mjj_Scaled_m%s_g%s_1fb_Nominal" % (mass,coupling)
    print hname
    h = f.Get(hname)
    if h:
        print h.Integral()
        #h = rebin_unitGeV_histogram(h)
        h.SetLineColor(ROOT.kRed)
        morph_h.append(h.Clone(hname))

for h in source_h:
    h.Draw("same")
for h in morph_h:
    h.Draw("same")
        

ROOT.gPad.Print("check.pdf")
ROOT.gPad.Print("check.C")
