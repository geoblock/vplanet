from benchmark import Benchmark, benchmark 
import astropy.units as u 
import pytest 
 
@benchmark( 
   { 
       "log.initial.system.Age": {"value": 0.000000, "unit": u.sec}, 
       "log.initial.system.Time": {"value": 0.000000, "unit": u.sec}, 
       "log.initial.system.TotAngMom": {"value": 1.227033e+42, "unit": (u.kg * u.m ** 2) / u.sec}, 
       "log.initial.system.TotEnergy": {"value": -5.271115e+41, "unit": u.Joule}, 
       "log.initial.system.PotEnergy": {"value": -5.271554e+41, "unit": u.Joule}, 
       "log.initial.system.KinEnergy": {"value": 4.396243e+37, "unit": u.Joule}, 
       "log.initial.system.DeltaTime": {"value": 0.000000, "unit": u.sec}, 
       "log.initial.sun.Mass": {"value": 1.630501e+30, "unit": u.kg}, 
       "log.initial.sun.Radius": {"value": 2.019571e+08, "unit": u.m}, 
       "log.initial.sun.RadGyra": {"value": 0.500000}, 
       "log.initial.sun.RotAngMom": {"value": 1.209054e+42, "unit": (u.kg * u.m ** 2) / u.sec}, 
       "log.initial.sun.RotVel": {"value": 1.468674e+04, "unit": u.m / u.sec}, 
       "log.initial.sun.BodyType": {"value": 0.000000}, 
       "log.initial.sun.RotRate": {"value": 7.272205e-05, "unit": 1 / u.sec}, 
       "log.initial.sun.RotPer": {"value": 8.640000e+04, "unit": u.sec}, 
       "log.initial.sun.Density": {"value": 4.725578e+04, "unit": u.kg / u.m ** 3}, 
       "log.initial.sun.HZLimitDryRunaway": {"value": 7.577545e+10, "unit": u.m}, 
       "log.initial.sun.HZLimRecVenus": {"value": 6.244324e+10, "unit": u.m}, 
       "log.initial.sun.HZLimRunaway": {"value": 8.153898e+10, "unit": u.m}, 
       "log.initial.sun.HZLimMoistGreenhouse": {"value": 8.262208e+10, "unit": u.m}, 
       "log.initial.sun.HZLimMaxGreenhouse": {"value": 1.400479e+11, "unit": u.m}, 
       "log.initial.sun.HZLimEarlyMars": {"value": 1.528036e+11, "unit": u.m}, 
       "log.initial.sun.Instellation": {"value": -1.000000, "unit": u.kg / u.sec ** 3}, 
       "log.initial.sun.CriticalSemiMajorAxis": {"value": -1.000000, "unit": u.m}, 
       "log.initial.sun.LXUVTot": {"value": 1.197774e+23, "unit": u.kg / u.sec ** 3}, 
       "log.initial.sun.LostEnergy": {"value": 5.562685e-309, "unit": u.Joule}, 
       "log.initial.sun.LostAngMom": {"value": 5.562685e-309, "unit": (u.kg * u.m ** 2) / u.sec}, 
       "log.initial.sun.Luminosity": {"value": 1.197774e+26, "unit": u.W}, 
       "log.initial.sun.LXUVStellar": {"value": 1.197774e+23, "unit": u.W}, 
       "log.initial.sun.Temperature": {"value": 5778.000000, "unit": u.K}, 
       "log.initial.sun.LXUVFrac": {"value": 0.001000}, 
       "log.initial.sun.RossbyNumber": {"value": 0.078260}, 
       "log.initial.sun.DRotPerDtStellar": {"value": 9.129602e-13}, 
       "log.initial.earth.Mass": {"value": 5.971546e+24, "unit": u.kg}, 
       "log.initial.earth.Obliquity": {"value": 0.855211, "unit": u.rad}, 
       "log.initial.earth.PrecA": {"value": 0.000000, "unit": u.rad}, 
       "log.initial.earth.Radius": {"value": 6.378100e+06, "unit": u.m}, 
       "log.initial.earth.RadGyra": {"value": 0.500000}, 
       "log.initial.earth.BodyType": {"value": 0.000000}, 
       "log.initial.earth.Density": {"value": 5494.449526, "unit": u.kg / u.m ** 3}, 
       "log.initial.earth.HZLimitDryRunaway": {"value": 6.255959e+10, "unit": u.m}, 
       "log.initial.earth.HZLimRecVenus": {"value": 6.244324e+10, "unit": u.m}, 
       "log.initial.earth.HZLimRunaway": {"value": 8.153898e+10, "unit": u.m}, 
       "log.initial.earth.HZLimMoistGreenhouse": {"value": 8.262208e+10, "unit": u.m}, 
       "log.initial.earth.HZLimMaxGreenhouse": {"value": 1.400479e+11, "unit": u.m}, 
       "log.initial.earth.HZLimEarlyMars": {"value": 1.528036e+11, "unit": u.m}, 
       "log.initial.earth.Instellation": {"value": 1292.179111, "unit": u.kg / u.sec ** 3}, 
       "log.initial.earth.Eccentricity": {"value": 0.200000}, 
       "log.initial.earth.MeanMotion": {"value": 4.081628e-07, "unit": 1 / u.sec}, 
       "log.initial.earth.OrbPeriod": {"value": 1.539382e+07, "unit": u.sec}, 
       "log.initial.earth.SemiMajorAxis": {"value": 8.676677e+10, "unit": u.m}, 
       "log.initial.earth.COPP": {"value": 0.000000}, 
       "log.initial.earth.TGlobal": {"value": 6.804611, "unit": u.deg_C}, 
       "log.initial.earth.AlbedoGlobal": {"value": 0.345662}, 
       "log.initial.earth.FluxInGlobal": {"value": 217.138067, "unit": u.kg / u.sec ** 3}, 
       "log.initial.earth.FluxOutGlobal": {"value": 217.521636, "unit": u.W / u.m ** 2}, 
       "log.initial.earth.TotIceMass": {"value": 0.000000, "unit": u.kg}, 
       "log.initial.earth.TotIceFlow": {"value": 0.000000, "unit": u.kg}, 
       "log.initial.earth.TotIceBalance": {"value": 0.000000, "unit": u.kg}, 
       "log.initial.earth.SkipSeas": {"value": 0.000000}, 
       "log.initial.earth.AreaIceCov": {"value": 0.000000}, 
       "log.initial.earth.Latitude": {"value": -83.402352, "unit": u.deg}, 
       "log.initial.earth.TempLat": {"value": 4.459198, "unit": u.deg_C}, 
       "log.initial.earth.AlbedoLat": {"value": 0.371914}, 
       "log.initial.earth.AnnInsol": {"value": 310.172750, "unit": u.W / u.m ** 2}, 
       "log.initial.earth.FluxMerid": {"value": -0.136586, "unit": u.PW}, 
       "log.initial.earth.FluxIn": {"value": 202.841625, "unit": u.W / u.m ** 2}, 
       "log.initial.earth.FluxOut": {"value": 212.619724, "unit": u.W / u.m ** 2}, 
       "log.initial.earth.DivFlux": {"value": -9.240234, "unit": u.W / u.m ** 2}, 
       "log.initial.earth.IceMass": {"value": 0.000000}, 
       "log.initial.earth.IceHeight": {"value": 0.000000, "unit": u.m}, 
       "log.initial.earth.DIceMassDt": {"value": 0.000000, "unit": u.m}, 
       "log.initial.earth.IceFlow": {"value": 0.000000, "unit": u.m / u.sec}, 
       "log.initial.earth.EnergyResL": {"value": 7.638334e-13, "unit": u.kg / u.sec ** 3}, 
       "log.initial.earth.EnergyResW": {"value": 2.335909e-12, "unit": u.kg / u.sec ** 3}, 
       "log.initial.earth.BedrockH": {"value": 0.000000, "unit": u.m}, 
       "log.initial.earth.TempLandLat": {"value": 270.645243, "unit": u.sec}, 
       "log.initial.earth.TempWaterLat": {"value": 280.969417, "unit": u.sec}, 
       "log.initial.earth.AlbedoLandLat": {"value": 0.493755}, 
       "log.initial.earth.AlbedoWaterLat": {"value": 0.309147}, 
       "log.initial.earth.TempMinLat": {"value": -7.526944, "unit": u.deg_C}, 
       "log.initial.earth.TempMaxLat": {"value": 18.544639, "unit": u.deg_C}, 
       "log.initial.earth.Snowball": {"value": 0.000000}, 
       "log.initial.earth.PlanckBAvg": {"value": 2.090000}, 
       "log.initial.earth.IceAccum": {"value": 0.212532}, 
       "log.initial.earth.IceAblate": {"value": -0.142974}, 
       "log.initial.earth.TempMaxLand": {"value": 307.355648, "unit": u.sec}, 
       "log.initial.earth.TempMaxWater": {"value": 283.915884, "unit": u.sec}, 
       "log.initial.earth.PeakInsol": {"value": 1104.513146, "unit": u.kg / u.sec ** 3}, 
       "log.initial.earth.IceCapNorthLand": {"value": 0.000000}, 
       "log.initial.earth.IceCapNorthSea": {"value": 0.000000}, 
       "log.initial.earth.IceCapSouthLand": {"value": 0.000000}, 
       "log.initial.earth.IceCapSouthSea": {"value": 0.000000}, 
       "log.initial.earth.IceBeltLand": {"value": 0.000000}, 
       "log.initial.earth.IceBeltSea": {"value": 0.000000}, 
       "log.initial.earth.SnowballLand": {"value": 0.000000}, 
       "log.initial.earth.SnowballSea": {"value": 0.000000}, 
       "log.initial.earth.IceFree": {"value": 1.000000}, 
       "log.initial.earth.IceCapNorthLatLand": {"value": 100.000000, "unit": u.rad}, 
       "log.initial.earth.IceCapNorthLatSea": {"value": 100.000000, "unit": u.rad}, 
       "log.initial.earth.IceCapSouthLatLand": {"value": 100.000000, "unit": u.rad}, 
       "log.initial.earth.IceCapSouthLatSea": {"value": 100.000000, "unit": u.rad}, 
       "log.initial.earth.IceBeltNorthLatLand": {"value": 100.000000, "unit": u.rad}, 
       "log.initial.earth.IceBeltNorthLatSea": {"value": 100.000000, "unit": u.rad}, 
       "log.initial.earth.IceBeltSouthLatLand": {"value": 100.000000, "unit": u.rad}, 
       "log.initial.earth.IceBeltSouthLatSea": {"value": 100.000000, "unit": u.rad}, 
       "log.final.system.Age": {"value": 3.155760e+10, "unit": u.sec, "rtol": 1e-4}, 
       "log.final.system.Time": {"value": 3.155760e+10, "unit": u.sec, "rtol": 1e-4}, 
       "log.final.system.TotAngMom": {"value": 1.227033e+42, "unit": (u.kg * u.m ** 2) / u.sec, "rtol": 1e-4}, 
       "log.final.system.TotEnergy": {"value": -5.271115e+41, "unit": u.Joule, "rtol": 1e-4}, 
       "log.final.system.PotEnergy": {"value": -5.271554e+41, "unit": u.Joule, "rtol": 1e-4}, 
       "log.final.system.KinEnergy": {"value": 4.396240e+37, "unit": u.Joule, "rtol": 1e-4}, 
       "log.final.system.DeltaTime": {"value": 3.155760e+10, "unit": u.sec, "rtol": 1e-4}, 
       "log.final.sun.Mass": {"value": 1.630501e+30, "unit": u.kg, "rtol": 1e-4}, 
       "log.final.sun.Radius": {"value": 2.019571e+08, "unit": u.m, "rtol": 1e-4}, 
       "log.final.sun.RadGyra": {"value": 0.500000, "rtol": 1e-4}, 
       "log.final.sun.RotAngMom": {"value": 1.209053e+42, "unit": (u.kg * u.m ** 2) / u.sec, "rtol": 1e-4}, 
       "log.final.sun.RotVel": {"value": 1.468673e+04, "unit": u.m / u.sec, "rtol": 1e-4}, 
       "log.final.sun.BodyType": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.sun.RotRate": {"value": 7.272203e-05, "unit": 1 / u.sec, "rtol": 1e-4}, 
       "log.final.sun.RotPer": {"value": 8.640003e+04, "unit": u.sec, "rtol": 1e-4}, 
       "log.final.sun.Density": {"value": 4.725578e+04, "unit": u.kg / u.m ** 3, "rtol": 1e-4}, 
       "log.final.sun.HZLimitDryRunaway": {"value": 7.577545e+10, "unit": u.m, "rtol": 1e-4}, 
       "log.final.sun.HZLimRecVenus": {"value": 6.244324e+10, "unit": u.m, "rtol": 1e-4}, 
       "log.final.sun.HZLimRunaway": {"value": 8.153898e+10, "unit": u.m, "rtol": 1e-4}, 
       "log.final.sun.HZLimMoistGreenhouse": {"value": 8.262208e+10, "unit": u.m, "rtol": 1e-4}, 
       "log.final.sun.HZLimMaxGreenhouse": {"value": 1.400479e+11, "unit": u.m, "rtol": 1e-4}, 
       "log.final.sun.HZLimEarlyMars": {"value": 1.528036e+11, "unit": u.m, "rtol": 1e-4}, 
       "log.final.sun.Instellation": {"value": -1.000000, "unit": u.kg / u.sec ** 3, "rtol": 1e-4}, 
       "log.final.sun.CriticalSemiMajorAxis": {"value": -1.000000, "unit": u.m, "rtol": 1e-4}, 
       "log.final.sun.LXUVTot": {"value": 1.197774e+23, "unit": u.kg / u.sec ** 3, "rtol": 1e-4}, 
       "log.final.sun.LostEnergy": {"value": 2.931930e+31, "unit": u.Joule, "rtol": 1e-4}, 
       "log.final.sun.LostAngMom": {"value": 4.031694e+35, "unit": (u.kg * u.m ** 2) / u.sec, "rtol": 1e-4}, 
       "log.final.sun.Luminosity": {"value": 1.197774e+26, "unit": u.W, "rtol": 1e-4}, 
       "log.final.sun.LXUVStellar": {"value": 1.197774e+23, "unit": u.W, "rtol": 1e-4}, 
       "log.final.sun.Temperature": {"value": 5778.000000, "unit": u.K, "rtol": 1e-4}, 
       "log.final.sun.LXUVFrac": {"value": 0.001000, "rtol": 1e-4}, 
       "log.final.sun.RossbyNumber": {"value": 0.078260, "rtol": 1e-4}, 
       "log.final.sun.DRotPerDtStellar": {"value": 9.129605e-13, "rtol": 1e-4}, 
       "log.final.earth.Mass": {"value": 5.971546e+24, "unit": u.kg, "rtol": 1e-4}, 
       "log.final.earth.Obliquity": {"value": 0.855211, "unit": u.rad, "rtol": 1e-4}, 
       "log.final.earth.PrecA": {"value": 0.000000, "unit": u.rad, "rtol": 1e-4}, 
       "log.final.earth.Radius": {"value": 6.378100e+06, "unit": u.m, "rtol": 1e-4}, 
       "log.final.earth.RadGyra": {"value": 0.500000, "rtol": 1e-4}, 
       "log.final.earth.BodyType": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.earth.Density": {"value": 5494.449526, "unit": u.kg / u.m ** 3, "rtol": 1e-4}, 
       "log.final.earth.HZLimitDryRunaway": {"value": 6.255901e+10, "unit": u.m, "rtol": 1e-4}, 
       "log.final.earth.HZLimRecVenus": {"value": 6.244324e+10, "unit": u.m, "rtol": 1e-4}, 
       "log.final.earth.HZLimRunaway": {"value": 8.153898e+10, "unit": u.m, "rtol": 1e-4}, 
       "log.final.earth.HZLimMoistGreenhouse": {"value": 8.262208e+10, "unit": u.m, "rtol": 1e-4}, 
       "log.final.earth.HZLimMaxGreenhouse": {"value": 1.400479e+11, "unit": u.m, "rtol": 1e-4}, 
       "log.final.earth.HZLimEarlyMars": {"value": 1.528036e+11, "unit": u.m, "rtol": 1e-4}, 
       "log.final.earth.Instellation": {"value": 1292.179111, "unit": u.kg / u.sec ** 3, "rtol": 1e-4}, 
       "log.final.earth.Eccentricity": {"value": 0.200000, "rtol": 1e-4}, 
       "log.final.earth.MeanMotion": {"value": 4.081628e-07, "unit": 1 / u.sec, "rtol": 1e-4}, 
       "log.final.earth.OrbPeriod": {"value": 1.539382e+07, "unit": u.sec, "rtol": 1e-4}, 
       "log.final.earth.SemiMajorAxis": {"value": 8.676677e+10, "unit": u.m, "rtol": 1e-4}, 
       "log.final.earth.COPP": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.earth.TGlobal": {"value": 6.801868, "unit": u.deg_C, "rtol": 1e-4}, 
       "log.final.earth.AlbedoGlobal": {"value": 0.345674, "rtol": 1e-4}, 
       "log.final.earth.FluxInGlobal": {"value": 217.130837, "unit": u.kg / u.sec ** 3, "rtol": 1e-4}, 
       "log.final.earth.FluxOutGlobal": {"value": 217.515904, "unit": u.W / u.m ** 2, "rtol": 1e-4}, 
       "log.final.earth.TotIceMass": {"value": 0.000000, "unit": u.kg, "rtol": 1e-4}, 
       "log.final.earth.TotIceFlow": {"value": 0.000000, "unit": u.kg, "rtol": 1e-4}, 
       "log.final.earth.TotIceBalance": {"value": 0.000000, "unit": u.kg, "rtol": 1e-4}, 
       "log.final.earth.SkipSeas": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.earth.AreaIceCov": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.earth.Latitude": {"value": 83.402352, "unit": u.deg, "rtol": 1e-4}, 
       "log.final.earth.TempLat": {"value": 3.366641, "unit": u.deg_C, "rtol": 1e-4}, 
       "log.final.earth.AlbedoLat": {"value": 0.376793, "rtol": 1e-4}, 
       "log.final.earth.AnnInsol": {"value": 310.172861, "unit": u.W / u.m ** 2, "rtol": 1e-4}, 
       "log.final.earth.FluxMerid": {"value": 0.127051, "unit": u.PW, "rtol": 1e-4}, 
       "log.final.earth.FluxIn": {"value": 201.230893, "unit": u.W / u.m ** 2, "rtol": 1e-4}, 
       "log.final.earth.FluxOut": {"value": 210.336281, "unit": u.W / u.m ** 2, "rtol": 1e-4}, 
       "log.final.earth.DivFlux": {"value": -8.595168, "unit": u.W / u.m ** 2, "rtol": 1e-4}, 
       "log.final.earth.IceMass": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.earth.IceHeight": {"value": 0.000000, "unit": u.m, "rtol": 1e-4}, 
       "log.final.earth.DIceMassDt": {"value": 0.000000, "unit": u.m, "rtol": 1e-4}, 
       "log.final.earth.IceFlow": {"value": 0.000000, "unit": u.m / u.sec, "rtol": 1e-4}, 
       "log.final.earth.EnergyResL": {"value": -0.414500, "unit": u.kg / u.sec ** 3, "rtol": 1e-4}, 
       "log.final.earth.EnergyResW": {"value": 0.113084, "unit": u.kg / u.sec ** 3, "rtol": 1e-4}, 
       "log.final.earth.BedrockH": {"value": 0.000000, "unit": u.m, "rtol": 1e-4}, 
       "log.final.earth.TempLandLat": {"value": 268.455021, "unit": u.sec, "rtol": 1e-4}, 
       "log.final.earth.TempWaterLat": {"value": 280.442325, "unit": u.sec, "rtol": 1e-4}, 
       "log.final.earth.AlbedoLandLat": {"value": 0.508116, "rtol": 1e-4}, 
       "log.final.earth.AlbedoWaterLat": {"value": 0.309142, "rtol": 1e-4}, 
       "log.final.earth.TempMinLat": {"value": -6.216524, "unit": u.deg_C, "rtol": 1e-4}, 
       "log.final.earth.TempMaxLat": {"value": 19.804704, "unit": u.deg_C, "rtol": 1e-4}, 
       "log.final.earth.Snowball": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.earth.PlanckBAvg": {"value": 2.090000, "rtol": 1e-4}, 
       "log.final.earth.IceAccum": {"value": 0.240870, "rtol": 1e-4}, 
       "log.final.earth.IceAblate": {"value": -0.196060, "rtol": 1e-4}, 
       "log.final.earth.TempMaxLand": {"value": 310.298650, "unit": u.sec, "rtol": 1e-4}, 
       "log.final.earth.TempMaxWater": {"value": 283.962486, "unit": u.sec, "rtol": 1e-4}, 
       "log.final.earth.PeakInsol": {"value": 1104.819215, "unit": u.kg / u.sec ** 3, "rtol": 1e-4}, 
       "log.final.earth.IceCapNorthLand": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.earth.IceCapNorthSea": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.earth.IceCapSouthLand": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.earth.IceCapSouthSea": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.earth.IceBeltLand": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.earth.IceBeltSea": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.earth.SnowballLand": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.earth.SnowballSea": {"value": 0.000000, "rtol": 1e-4}, 
       "log.final.earth.IceFree": {"value": 1.000000, "rtol": 1e-4}, 
       "log.final.earth.IceCapNorthLatLand": {"value": 100.000000, "unit": u.rad, "rtol": 1e-4}, 
       "log.final.earth.IceCapNorthLatSea": {"value": 100.000000, "unit": u.rad, "rtol": 1e-4}, 
       "log.final.earth.IceCapSouthLatLand": {"value": 100.000000, "unit": u.rad, "rtol": 1e-4}, 
       "log.final.earth.IceCapSouthLatSea": {"value": 100.000000, "unit": u.rad, "rtol": 1e-4}, 
       "log.final.earth.IceBeltNorthLatLand": {"value": 100.000000, "unit": u.rad, "rtol": 1e-4}, 
       "log.final.earth.IceBeltNorthLatSea": {"value": 100.000000, "unit": u.rad, "rtol": 1e-4}, 
       "log.final.earth.IceBeltSouthLatLand": {"value": 100.000000, "unit": u.rad, "rtol": 1e-4}, 
       "log.final.earth.IceBeltSouthLatSea": {"value": 100.000000, "unit": u.rad, "rtol": 1e-4}, 
   } 
)
class TestForceEccObl(Benchmark): 
   pass 
