import matplotlib.pyplot as plt



class WayloAddrEnv:
    def __init__(self, sample_rate):
        self.sample_rate = sample_rate
        self.vol = 0
        self.position = 0
        self.max_volume = 1.0
        self.max_volume = 1.0
        self.fall_rate_change_volume = .65
        self.attack_rate_secs = 1 
        self.fall_rate_1_secs = 0.2
        self.fall_rate_2_secs = .5
        self.release_rate_secs = 1
        self.rate_scale = 0.5 #1 is one sec , 2 is 2 secs  
        self.state = 1 # 0 is idle , 1 is attack, 2 is decay one , 3 is decay 2 , 4 is release 
    
    def process(self):
            match self.state:
                case 1:
                    self.vol = self.vol + self.attack_rate_secs/(float(self.sample_rate)*self.rate_scale)
                    if self.vol >= self.max_volume:
                        self.state = 2
                        return(self.vol)
                    else:
                        return(self.vol)
                case 2:
                    self.vol = self.vol - self.fall_rate_1_secs/(float(self.sample_rate)*self.rate_scale)
                    if self.vol <= self.fall_rate_change_volume:
                        self.state = 3
                        return(self.vol)
                        
                    else:
                        return(self.vol)
                case 3:
                    self.vol = self.vol - self.fall_rate_2_secs/(float(self.sample_rate)*self.rate_scale)
                    if self.vol <= 0:
                        self.state = 0
                        return(self.vol)
                        
                    else:
                        return(self.vol)
                case 4:
                    self.vol = self.vol - self.release_rate_secs/(float(self.sample_rate)*self.rate_scale)
                    print(self.vol)
                    if self.vol <= 0:
                        self.state = 0
                        return(self.vol)    
                    else:
                        return(self.vol) 
                case 0:
                        return(self.vol)
    def reset(self):

        self.vol = 0
        self.state = 1



output = []
times = []   

sample_rate = 100000
env = WayloAddrEnv(sample_rate)  
for t in range(1,5*100000):
    #times.append(t)
    print(t)
    val = (env.process())
    if val < 0 : val = 0.0 
    print(val)
    #output.append(val)



env.reset()

for t in range(1,5*100000):
    times.append(t)
    print(t)
    val = (env.process())
    if val < 0 : val = 0.0 
    print(val)
    output.append(val)

times_out = [t/float(100000) for t in times]
# output_out = [float(v)/100.0 for v in output]
plt.plot(times_out, output)
plt.show()



    



