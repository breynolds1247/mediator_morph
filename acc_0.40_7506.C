void acc_0.40_7506()
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
   
   TH2D *frame__5 = new TH2D("frame__5","",10,0,4,10,0.01,1);
   
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
   frame__5->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(frame__5);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   frame__5->SetLineColor(ci);
   frame__5->GetXaxis()->SetLabelFont(42);
   frame__5->GetXaxis()->SetLabelSize(0.035);
   frame__5->GetXaxis()->SetTitleSize(0.035);
   frame__5->GetXaxis()->SetTitleFont(42);
   frame__5->GetYaxis()->SetLabelFont(42);
   frame__5->GetYaxis()->SetLabelSize(0.035);
   frame__5->GetYaxis()->SetTitleSize(0.035);
   frame__5->GetYaxis()->SetTitleOffset(0);
   frame__5->GetYaxis()->SetTitleFont(42);
   frame__5->GetZaxis()->SetLabelFont(42);
   frame__5->GetZaxis()->SetLabelSize(0.035);
   frame__5->GetZaxis()->SetTitleSize(0.035);
   frame__5->GetZaxis()->SetTitleFont(42);
   frame__5->Draw("");
   
   Double_t _fx9[8] = {
   0.65,
   0.75,
   1.15,
   1.05,
   1.7,
   0.85,
   0.95,
   2};
   Double_t _fy9[8] = {
   0.384,
   0.414,
   0.435,
   0.447,
   0.444,
   0.429,
   0.431,
   0.414};
   TGraph *graph = new TGraph(8,_fx9,_fy9);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(8);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph9 = new TH1F("Graph_Graph9","",100,0.515,2.135);
   Graph_Graph9->SetMinimum(0.3777);
   Graph_Graph9->SetMaximum(0.4533);
   Graph_Graph9->SetDirectory(0);
   Graph_Graph9->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph9->SetLineColor(ci);
   Graph_Graph9->GetXaxis()->SetLabelFont(42);
   Graph_Graph9->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph9->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph9->GetXaxis()->SetTitleFont(42);
   Graph_Graph9->GetYaxis()->SetLabelFont(42);
   Graph_Graph9->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph9->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph9->GetYaxis()->SetTitleOffset(0);
   Graph_Graph9->GetYaxis()->SetTitleFont(42);
   Graph_Graph9->GetZaxis()->SetLabelFont(42);
   Graph_Graph9->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph9->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph9->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph9);
   
   
   TF1 *mp10 = new TF1("mp","[0]/(1+exp(-(x-[1])*[2]))*(1+exp(-(x-[3])*[4]))",0.39,2);
   mp10->SetFillColor(19);
   mp10->SetFillStyle(0);
   mp10->SetLineColor(2);
   mp10->SetLineWidth(2);
   mp10->SetChisquare(0.002629597);
   mp10->SetNDF(3);
   mp10->GetXaxis()->SetLabelFont(42);
   mp10->GetXaxis()->SetLabelSize(0.035);
   mp10->GetXaxis()->SetTitleSize(0.035);
   mp10->GetXaxis()->SetTitleFont(42);
   mp10->GetYaxis()->SetLabelFont(42);
   mp10->GetYaxis()->SetLabelSize(0.035);
   mp10->GetYaxis()->SetTitleSize(0.035);
   mp10->GetYaxis()->SetTitleOffset(0);
   mp10->GetYaxis()->SetTitleFont(42);
   mp10->SetParameter(0,0.4173426);
   mp10->SetParError(0,0.1128687);
   mp10->SetParLimits(0,0,0);
   mp10->SetParameter(1,1.192873e-05);
   mp10->SetParError(1,8.906881);
   mp10->SetParLimits(1,0,0);
   mp10->SetParameter(2,0.0616661);
   mp10->SetParError(2,0.1269994);
   mp10->SetParLimits(2,0,0);
   mp10->SetParameter(3,10.49773);
   mp10->SetParError(3,0.3632345);
   mp10->SetParLimits(3,1,20);
   mp10->SetParameter(4,-0.003638518);
   mp10->SetParError(4,2.94839);
   mp10->SetParLimits(4,-100,0);
   graph->GetListOfFunctions()->Add(mp10);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
