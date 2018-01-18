void acc_0.15_7506()
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
   
   TH2D *frame__1 = new TH2D("frame__1","",10,0,4,10,0.01,1);
   
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
   frame__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__1->SetLineColor(ci);
   frame__1->GetXaxis()->SetLabelFont(42);
   frame__1->GetXaxis()->SetLabelSize(0.035);
   frame__1->GetXaxis()->SetTitleSize(0.035);
   frame__1->GetXaxis()->SetTitleFont(42);
   frame__1->GetYaxis()->SetLabelFont(42);
   frame__1->GetYaxis()->SetLabelSize(0.035);
   frame__1->GetYaxis()->SetTitleSize(0.035);
   frame__1->GetYaxis()->SetTitleOffset(0);
   frame__1->GetYaxis()->SetTitleFont(42);
   frame__1->GetZaxis()->SetLabelFont(42);
   frame__1->GetZaxis()->SetLabelSize(0.035);
   frame__1->GetZaxis()->SetTitleSize(0.035);
   frame__1->GetZaxis()->SetTitleFont(42);
   frame__1->Draw("");
   
   Double_t _fx1[11] = {
   0.65,
   0.75,
   0.45,
   0.55,
   1,
   0.35,
   1.5,
   1.7,
   0.85,
   0.95,
   2};
   Double_t _fy1[11] = {
   0.41,
   0.447,
   0.119,
   0.352,
   0.471,
   0.011,
   0.471,
   0.472,
   0.462,
   0.462,
   0.465};
   TGraph *graph = new TGraph(11,_fx1,_fy1);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,0.185,2.165);
   Graph_Graph1->SetMinimum(0.0099);
   Graph_Graph1->SetMaximum(0.5181);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleOffset(0);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   
   TF1 *mp2 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))",0.39,2);
   mp2->SetFillColor(19);
   mp2->SetFillStyle(0);
   mp2->SetLineColor(2);
   mp2->SetLineWidth(2);
   mp2->SetChisquare(0.001638808);
   mp2->SetNDF(5);
   mp2->GetXaxis()->SetLabelFont(42);
   mp2->GetXaxis()->SetLabelSize(0.035);
   mp2->GetXaxis()->SetTitleSize(0.035);
   mp2->GetXaxis()->SetTitleFont(42);
   mp2->GetYaxis()->SetLabelFont(42);
   mp2->GetYaxis()->SetLabelSize(0.035);
   mp2->GetYaxis()->SetTitleSize(0.035);
   mp2->GetYaxis()->SetTitleOffset(0);
   mp2->GetYaxis()->SetTitleFont(42);
   mp2->SetParameter(0,0.4635978);
   mp2->SetParError(0,0.01180296);
   mp2->SetParLimits(0,0,0);
   mp2->SetParameter(1,0.5000607);
   mp2->SetParError(1,0.007201259);
   mp2->SetParLimits(1,0,0);
   mp2->SetParameter(2,18.01447);
   mp2->SetParError(2,0.02560203);
   mp2->SetParLimits(2,0,0);
   mp2->SetParameter(3,8.426787);
   mp2->SetParError(3,0.2370634);
   mp2->SetParLimits(3,1,20);
   mp2->SetParameter(4,-8.790344);
   mp2->SetParError(4,1.728111);
   mp2->SetParLimits(4,-100,0);
   graph->GetListOfFunctions()->Add(mp2);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
