void acc_0.20_7503()
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
   
   TH2D *frame__16 = new TH2D("frame__16","",10,0,4,10,0.01,1);
   
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
   frame__16->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__16);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__16->SetLineColor(ci);
   frame__16->GetXaxis()->SetLabelFont(42);
   frame__16->GetXaxis()->SetLabelSize(0.035);
   frame__16->GetXaxis()->SetTitleSize(0.035);
   frame__16->GetXaxis()->SetTitleFont(42);
   frame__16->GetYaxis()->SetLabelFont(42);
   frame__16->GetYaxis()->SetLabelSize(0.035);
   frame__16->GetYaxis()->SetTitleSize(0.035);
   frame__16->GetYaxis()->SetTitleOffset(0);
   frame__16->GetYaxis()->SetTitleFont(42);
   frame__16->GetZaxis()->SetLabelFont(42);
   frame__16->GetZaxis()->SetLabelSize(0.035);
   frame__16->GetZaxis()->SetTitleSize(0.035);
   frame__16->GetZaxis()->SetTitleFont(42);
   frame__16->Draw("");
   
   Double_t _fx31[10] = {
   0.65,
   0.75,
   0.45,
   0.55,
   1,
   1.5,
   1.7,
   0.85,
   0.95,
   2};
   Double_t _fy31[10] = {
   0.221,
   0.235,
   0.139,
   0.205,
   0.244,
   0.243,
   0.243,
   0.244,
   0.244,
   0.236};
   TGraph *graph = new TGraph(10,_fx31,_fy31);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph31 = new TH1F("Graph_Graph31","",100,0.295,2.155);
   Graph_Graph31->SetMinimum(0.1285);
   Graph_Graph31->SetMaximum(0.2545);
   Graph_Graph31->SetDirectory(0);
   Graph_Graph31->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph31->SetLineColor(ci);
   Graph_Graph31->GetXaxis()->SetLabelFont(42);
   Graph_Graph31->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph31->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph31->GetXaxis()->SetTitleFont(42);
   Graph_Graph31->GetYaxis()->SetLabelFont(42);
   Graph_Graph31->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph31->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph31->GetYaxis()->SetTitleOffset(0);
   Graph_Graph31->GetYaxis()->SetTitleFont(42);
   Graph_Graph31->GetZaxis()->SetLabelFont(42);
   Graph_Graph31->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph31->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph31->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph31);
   
   
   TF1 *mp32 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))",0.39,2);
   mp32->SetFillColor(19);
   mp32->SetFillStyle(0);
   mp32->SetLineColor(2);
   mp32->SetLineWidth(2);
   mp32->SetChisquare(0.0004325495);
   mp32->SetNDF(5);
   mp32->GetXaxis()->SetLabelFont(42);
   mp32->GetXaxis()->SetLabelSize(0.035);
   mp32->GetXaxis()->SetTitleSize(0.035);
   mp32->GetXaxis()->SetTitleFont(42);
   mp32->GetYaxis()->SetLabelFont(42);
   mp32->GetYaxis()->SetLabelSize(0.035);
   mp32->GetYaxis()->SetTitleSize(0.035);
   mp32->GetYaxis()->SetTitleOffset(0);
   mp32->GetYaxis()->SetTitleFont(42);
   mp32->SetParameter(0,0.2452441);
   mp32->SetParError(0,0.004323492);
   mp32->SetParLimits(0,0,0);
   mp32->SetParameter(1,0.3927732);
   mp32->SetParError(1,0.01773318);
   mp32->SetParLimits(1,0,0);
   mp32->SetParameter(2,8.217832);
   mp32->SetParError(2,1.041914);
   mp32->SetParLimits(2,0,0);
   mp32->SetParameter(3,11.70782);
   mp32->SetParError(3,0.124226);
   mp32->SetParLimits(3,1,20);
   mp32->SetParameter(4,-0.6658959);
   mp32->SetParError(4,0.5493896);
   mp32->SetParLimits(4,-100,0);
   graph->GetListOfFunctions()->Add(mp32);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
