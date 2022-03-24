#version 330 core

out vec4 fragColor;
in vec4 position;

uniform float u_time;
uniform float u_source[200];
uniform int u_source_count;

// takes index
// returns corresponding value of u_source
float index_data(int i) {
    if ( i==0 ) return u_source[0];
    else if ( i==1 ) return u_source[1];
    else if ( i==2 ) return u_source[2];
    else if ( i==3 ) return u_source[3];
    else if ( i==4 ) return u_source[4];
    else if ( i==5 ) return u_source[5];
    else if ( i==6 ) return u_source[6];
    else if ( i==7 ) return u_source[7];
    else if ( i==8 ) return u_source[8];
    else if ( i==9 ) return u_source[9];
    else if ( i==10 ) return u_source[10];
    else if ( i==11 ) return u_source[11];
    else if ( i==12 ) return u_source[12];
    else if ( i==13 ) return u_source[13];
    else if ( i==14 ) return u_source[14];
    else if ( i==15 ) return u_source[15];
    else if ( i==16 ) return u_source[16];
    else if ( i==17 ) return u_source[17];
    else if ( i==18 ) return u_source[18];
    else if ( i==19 ) return u_source[19];
    else if ( i==20 ) return u_source[20];
    else if ( i==21 ) return u_source[21];
    else if ( i==22 ) return u_source[22];
    else if ( i==23 ) return u_source[23];
    else if ( i==24 ) return u_source[24];
    else if ( i==25 ) return u_source[25];
    else if ( i==26 ) return u_source[26];
    else if ( i==27 ) return u_source[27];
    else if ( i==28 ) return u_source[28];
    else if ( i==29 ) return u_source[29];
    else if ( i==30 ) return u_source[30];
    else if ( i==31 ) return u_source[31];
    else if ( i==32 ) return u_source[32];
    else if ( i==33 ) return u_source[33];
    else if ( i==34 ) return u_source[34];
    else if ( i==35 ) return u_source[35];
    else if ( i==36 ) return u_source[36];
    else if ( i==37 ) return u_source[37];
    else if ( i==38 ) return u_source[38];
    else if ( i==39 ) return u_source[39];
    else if ( i==40 ) return u_source[40];
    else if ( i==41 ) return u_source[41];
    else if ( i==42 ) return u_source[42];
    else if ( i==43 ) return u_source[43];
    else if ( i==44 ) return u_source[44];
    else if ( i==45 ) return u_source[45];
    else if ( i==46 ) return u_source[46];
    else if ( i==47 ) return u_source[47];
    else if ( i==48 ) return u_source[48];
    else if ( i==49 ) return u_source[49];
    else if ( i==50 ) return u_source[50];
    else if ( i==51 ) return u_source[51];
    else if ( i==52 ) return u_source[52];
    else if ( i==53 ) return u_source[53];
    else if ( i==54 ) return u_source[54];
    else if ( i==55 ) return u_source[55];
    else if ( i==56 ) return u_source[56];
    else if ( i==57 ) return u_source[57];
    else if ( i==58 ) return u_source[58];
    else if ( i==59 ) return u_source[59];
    else if ( i==60 ) return u_source[60];
    else if ( i==61 ) return u_source[61];
    else if ( i==62 ) return u_source[62];
    else if ( i==63 ) return u_source[63];
    else if ( i==64 ) return u_source[64];
    else if ( i==65 ) return u_source[65];
    else if ( i==66 ) return u_source[66];
    else if ( i==67 ) return u_source[67];
    else if ( i==68 ) return u_source[68];
    else if ( i==69 ) return u_source[69];
    else if ( i==70 ) return u_source[70];
    else if ( i==71 ) return u_source[71];
    else if ( i==72 ) return u_source[72];
    else if ( i==73 ) return u_source[73];
    else if ( i==74 ) return u_source[74];
    else if ( i==75 ) return u_source[75];
    else if ( i==76 ) return u_source[76];
    else if ( i==77 ) return u_source[77];
    else if ( i==78 ) return u_source[78];
    else if ( i==79 ) return u_source[79];
    else if ( i==80 ) return u_source[80];
    else if ( i==81 ) return u_source[81];
    else if ( i==82 ) return u_source[82];
    else if ( i==83 ) return u_source[83];
    else if ( i==84 ) return u_source[84];
    else if ( i==85 ) return u_source[85];
    else if ( i==86 ) return u_source[86];
    else if ( i==87 ) return u_source[87];
    else if ( i==88 ) return u_source[88];
    else if ( i==89 ) return u_source[89];
    else if ( i==90 ) return u_source[90];
    else if ( i==91 ) return u_source[91];
    else if ( i==92 ) return u_source[92];
    else if ( i==93 ) return u_source[93];
    else if ( i==94 ) return u_source[94];
    else if ( i==95 ) return u_source[95];
    else if ( i==96 ) return u_source[96];
    else if ( i==97 ) return u_source[97];
    else if ( i==98 ) return u_source[98];
    else if ( i==99 ) return u_source[99];
    else if ( i==100 ) return u_source[100];
    else if ( i==101 ) return u_source[101];
    else if ( i==102 ) return u_source[102];
    else if ( i==103 ) return u_source[103];
    else if ( i==104 ) return u_source[104];
    else if ( i==105 ) return u_source[105];
    else if ( i==106 ) return u_source[106];
    else if ( i==107 ) return u_source[107];
    else if ( i==108 ) return u_source[108];
    else if ( i==109 ) return u_source[109];
    else if ( i==110 ) return u_source[110];
    else if ( i==111 ) return u_source[111];
    else if ( i==112 ) return u_source[112];
    else if ( i==113 ) return u_source[113];
    else if ( i==114 ) return u_source[114];
    else if ( i==115 ) return u_source[115];
    else if ( i==116 ) return u_source[116];
    else if ( i==117 ) return u_source[117];
    else if ( i==118 ) return u_source[118];
    else if ( i==119 ) return u_source[119];
    else if ( i==120 ) return u_source[120];
    else if ( i==121 ) return u_source[121];
    else if ( i==122 ) return u_source[122];
    else if ( i==123 ) return u_source[123];
    else if ( i==124 ) return u_source[124];
    else if ( i==125 ) return u_source[125];
    else if ( i==126 ) return u_source[126];
    else if ( i==127 ) return u_source[127];
    else if ( i==128 ) return u_source[128];
    else if ( i==129 ) return u_source[129];
    else if ( i==130 ) return u_source[130];
    else if ( i==131 ) return u_source[131];
    else if ( i==132 ) return u_source[132];
    else if ( i==133 ) return u_source[133];
    else if ( i==134 ) return u_source[134];
    else if ( i==135 ) return u_source[135];
    else if ( i==136 ) return u_source[136];
    else if ( i==137 ) return u_source[137];
    else if ( i==138 ) return u_source[138];
    else if ( i==139 ) return u_source[139];
    else if ( i==140 ) return u_source[140];
    else if ( i==141 ) return u_source[141];
    else if ( i==142 ) return u_source[142];
    else if ( i==143 ) return u_source[143];
    else if ( i==144 ) return u_source[144];
    else if ( i==145 ) return u_source[145];
    else if ( i==146 ) return u_source[146];
    else if ( i==147 ) return u_source[147];
    else if ( i==148 ) return u_source[148];
    else if ( i==149 ) return u_source[149];
    else if ( i==150 ) return u_source[150];
    else if ( i==151 ) return u_source[151];
    else if ( i==152 ) return u_source[152];
    else if ( i==153 ) return u_source[153];
    else if ( i==154 ) return u_source[154];
    else if ( i==155 ) return u_source[155];
    else if ( i==156 ) return u_source[156];
    else if ( i==157 ) return u_source[157];
    else if ( i==158 ) return u_source[158];
    else if ( i==159 ) return u_source[159];
    else if ( i==160 ) return u_source[160];
    else if ( i==161 ) return u_source[161];
    else if ( i==162 ) return u_source[162];
    else if ( i==163 ) return u_source[163];
    else if ( i==164 ) return u_source[164];
    else if ( i==165 ) return u_source[165];
    else if ( i==166 ) return u_source[166];
    else if ( i==167 ) return u_source[167];
    else if ( i==168 ) return u_source[168];
    else if ( i==169 ) return u_source[169];
    else if ( i==170 ) return u_source[170];
    else if ( i==171 ) return u_source[171];
    else if ( i==172 ) return u_source[172];
    else if ( i==173 ) return u_source[173];
    else if ( i==174 ) return u_source[174];
    else if ( i==175 ) return u_source[175];
    else if ( i==176 ) return u_source[176];
    else if ( i==177 ) return u_source[177];
    else if ( i==178 ) return u_source[178];
    else if ( i==179 ) return u_source[179];
    else if ( i==180 ) return u_source[180];
    else if ( i==181 ) return u_source[181];
    else if ( i==182 ) return u_source[182];
    else if ( i==183 ) return u_source[183];
    else if ( i==184 ) return u_source[184];
    else if ( i==185 ) return u_source[185];
    else if ( i==186 ) return u_source[186];
    else if ( i==187 ) return u_source[187];
    else if ( i==188 ) return u_source[188];
    else if ( i==189 ) return u_source[189];
    else if ( i==190 ) return u_source[190];
    else if ( i==191 ) return u_source[191];
    else if ( i==192 ) return u_source[192];
    else if ( i==193 ) return u_source[193];
    else if ( i==194 ) return u_source[194];
    else if ( i==195 ) return u_source[195];
    else if ( i==196 ) return u_source[196];
    else if ( i==197 ) return u_source[197];
    else if ( i==198 ) return u_source[198];
    else if ( i==199 ) return u_source[199];
}

// entry point
void main()
{
    // wave charactaristics
    float normalize_intensity = 0.5f / u_source_count;
    
    
    // calculate intensity
    float intensity = 0.0f;
    float r = 0.0f;
    
    for (int i=0; i < u_source_count; i++) {
        r = pow(pow(position.x + 1.0f - index_data(i*5), 2) + pow(position.y + 1.0f - index_data(i*5 + 1), 2), 0.5f);
        intensity += index_data(i*5 + 4) * normalize_intensity * sin(index_data(i*5 + 2)*(r - index_data(i*5 + 3)*u_time)) + normalize_intensity;
    }

    
    fragColor = vec4(intensity, 0.0f, 0.0f, 1.0f);
}


