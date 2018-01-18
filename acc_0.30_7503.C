void acc_0.30_7503()
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
   
   TH2D *frame__18 = new TH2D("frame__18","",10,0,4,10,0.01,1);
   
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
   frame__18->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__18);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__18->SetLineColor(ci);
   frame__18->GetXaxis()->SetLabelFont(42);
   frame__18->GetXaxis()->SetLabelSize(0.035);
   frame__18->GetXaxis()->SetTitleSize(0.035);
   frame__18->GetXaxis()->SetTitleFont(42);
   frame__18->GetYaxis()->SetLabelFont(42);
   frame__18->GetYaxis()->SetLabelSize(0.035);
   frame__18->GetYaxis()->SetTitleSize(0.035);
   frame__18->GetYaxis()->SetTitleOffset(0);
   frame__18->GetYaxis()->SetTitleFont(42);
   frame__18->GetZaxis()->SetLabelFont(42);
   frame__18->GetZaxis()->SetLabelSize(0.035);
   frame__18->GetZaxis()->SetTitleSize(0.035);
   frame__18->GetZaxis()->SetTitleFont(42);
   frame__18->Draw("");
   
   Double_t _fx35[11] = {
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
   Double_t _fy35[11] = {
   0.221,
   0.231,
   0.13,
   0.195,
   0.239,
   0.242,
   0.242,
   0.242,
   0.246,
   0.238,
   0.232};
   TGraph *graph = new TGraph(11,_fx35,_fy35);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph35 = new TH1F("Graph_Graph35","",100,0.295,2.155);
   Graph_Graph35->SetMinimum(0.1184);
   Graph_Graph35->SetMaximum(0.2576);
   Graph_Graph35->SetDirectory(0);
   Graph_Graph35->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph35->SetLineColor(ci);
   Graph_Graph35->GetXaxis()->SetLabelFont(42);
   Graph_Graph35->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph35->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph35->GetXaxis()->SetTitleFont(42);
   Graph_Graph35->GetYaxis()->SetLabelFont(42);
   Graph_Graph35->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph35->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph35->GetYaxis()->SetTitleOffset(0);
   Graph_Graph35->GetYaxis()->SetTitleFont(42);
   Graph_Graph35->GetZaxis()->SetLabelFont(42);
   Graph_Graph35->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph35->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph35->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph35);
   
   
   TF1 *mp36 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))",0.39,2);
   mp36->SetFillColor(19);
   mp36->SetFillStyle(0);
   mp36->SetLineColor(2);
   mp36->SetLineWidth(2);
   mp36->SetChisquare(0.0001655166);
   mp36->SetNDF(6);
   mp36->GetXaxis()->SetLabelFont(42);
   mp36->GetXaxis()->SetLabelSize(0.035);
   mp36->GetXaxis()->SetTitleSize(0.035);
   mp36->GetXaxis()->SetTitleFont(42);
   mp36->GetYaxis()->SetLabelFont(42);
   mp36->GetYaxis()->SetLabelSize(0.035);
   mp36->GetYaxis()->SetTitleSize(0.035);
   mp36->GetYaxis()->SetTitleOffset(0);
   mp36->GetYaxis()->SetTitleFont(42);
   mp36->SetParameter(0,0.2398556);
   mp36->SetParError(0,0.02106845);
   mp36->SetParLimits(0,0,0);
   mp36->SetParameter(1,0.4352162);
   mp36->SetParError(1,0.005307673);
   mp36->SetParLimits(1,0,0);
   mp36->SetParameter(2,12.18515);
   mp36->SetParError(2,0.7995712);
   mp36->SetParLimits(2,0,0);
   mp36->SetParameter(3,2.993058);
   mp36->SetParError(3,4.258439e-06);
   mp36->SetParLimits(3,1,20);
   mp36->SetParameter(4,-11.03346);
   mp36->SetParError(4,0.2984826);
   mp36->SetParLimits(4,-100,0);
   graph->GetListOfFunctions()->Add(mp36);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
