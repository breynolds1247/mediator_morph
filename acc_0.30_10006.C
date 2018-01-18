void acc_0.30_10006()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Dec 12 18:15:33 2017) by ROOT version6.10/08
   TCanvas *c1 = new TCanvas("c1", "c1",10,44,700,500);
   gStyle->SetOptFit(1);
   c1->SetHighLightColor(2);
   c1->Range(-0.5,-0.11375,4.5,1.12375);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2D *frame__12 = new TH2D("frame__12","",10,0,4,10,0.01,1);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("frame");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 0      ");
   ptstats_LaTex = ptstats->AddText("Mean x =      0");
   ptstats_LaTex = ptstats->AddText("Mean y =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev x =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(11111);
   ptstats->Draw();
   frame__12->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__12);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__12->SetLineColor(ci);
   frame__12->GetXaxis()->SetLabelFont(42);
   frame__12->GetXaxis()->SetLabelSize(0.035);
   frame__12->GetXaxis()->SetTitleSize(0.035);
   frame__12->GetXaxis()->SetTitleFont(42);
   frame__12->GetYaxis()->SetLabelFont(42);
   frame__12->GetYaxis()->SetLabelSize(0.035);
   frame__12->GetYaxis()->SetTitleSize(0.035);
   frame__12->GetYaxis()->SetTitleOffset(0);
   frame__12->GetYaxis()->SetTitleFont(42);
   frame__12->GetZaxis()->SetLabelFont(42);
   frame__12->GetZaxis()->SetLabelSize(0.035);
   frame__12->GetZaxis()->SetTitleSize(0.035);
   frame__12->GetZaxis()->SetTitleFont(42);
   frame__12->Draw("");
   
   Double_t _fx23[11] = {
   0.65,
   0.75,
   0.45,
   0.55,
   1,
   1.05,
   1.5,
   1.7,
   0.85,
   0.95,
   2};
   Double_t _fy23[11] = {
   0.32,
   0.387,
   0.014,
   0.148,
   0.445,
   0.454,
   0.468,
   0.466,
   0.428,
   0.441,
   0.447};
   TGraph *graph = new TGraph(11,_fx23,_fy23);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph23 = new TH1F("Graph_Graph23","",100,0.295,2.155);
   Graph_Graph23->SetMinimum(0.0126);
   Graph_Graph23->SetMaximum(0.5134);
   Graph_Graph23->SetDirectory(0);
   Graph_Graph23->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph23->SetLineColor(ci);
   Graph_Graph23->GetXaxis()->SetLabelFont(42);
   Graph_Graph23->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph23->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph23->GetXaxis()->SetTitleFont(42);
   Graph_Graph23->GetYaxis()->SetLabelFont(42);
   Graph_Graph23->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph23->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph23->GetYaxis()->SetTitleOffset(0);
   Graph_Graph23->GetYaxis()->SetTitleFont(42);
   Graph_Graph23->GetZaxis()->SetLabelFont(42);
   Graph_Graph23->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph23->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph23->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph23);
   
   
   TF1 *mp24 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))",0.39,2);
   mp24->SetFillColor(19);
   mp24->SetFillStyle(0);
   mp24->SetLineColor(2);
   mp24->SetLineWidth(2);
   mp24->SetChisquare(0.002222308);
   mp24->SetNDF(6);
   mp24->GetXaxis()->SetLabelFont(42);
   mp24->GetXaxis()->SetLabelSize(0.035);
   mp24->GetXaxis()->SetTitleSize(0.035);
   mp24->GetXaxis()->SetTitleFont(42);
   mp24->GetYaxis()->SetLabelFont(42);
   mp24->GetYaxis()->SetLabelSize(0.035);
   mp24->GetYaxis()->SetTitleSize(0.035);
   mp24->GetYaxis()->SetTitleOffset(0);
   mp24->GetYaxis()->SetTitleFont(42);
   mp24->SetParameter(0,0.2247937);
   mp24->SetParError(0,0.002774348);
   mp24->SetParLimits(0,0,0.5);
   mp24->SetParameter(1,0.6004263);
   mp24->SetParError(1,0.007780389);
   mp24->SetParLimits(1,0,2);
   mp24->SetParameter(2,15.60067);
   mp24->SetParError(2,0.2217819);
   mp24->SetParLimits(2,5,20);
   mp24->SetParameter(3,1.063512);
   mp24->SetParError(3,0.226894);
   mp24->SetParLimits(3,1,20);
   mp24->SetParameter(4,-1.252943e-05);
   mp24->SetParError(4,1.368054);
   mp24->SetParLimits(4,-100,0);
   graph->GetListOfFunctions()->Add(mp24);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
