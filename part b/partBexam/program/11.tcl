# Create simulator
set ns [new Simulator]

# Trace files
set tf [open out.tr w]
$ns trace-all $tf

set nf [open lab.nam w]
$ns namtrace-all $nf

# Flow color
$ns color 0 blue

# Create nodes
set n0 [$ns node]
$n0 color "red"

set n1 [$ns node]
$n1 color "red"

set n2 [$ns node]
$n2 color "red"

set n3 [$ns node]
$n3 color "red"

set n4 [$ns node]
$n4 color "magenta"

set n5 [$ns node]
$n5 color "magenta"

set n6 [$ns node]
$n6 color "magenta"

set n7 [$ns node]
$n7 color "magenta"

# -------------------------------
# Node positioning (IMPORTANT)
# -------------------------------
# Node positioning (works correctly with LAN)

# Left LAN (centered at n3)
$ns at 0.0 "$n3 set X_ 150"
$ns at 0.0 "$n3 set Y_ 200"

$ns at 0.0 "$n0 set X_ 100"
$ns at 0.0 "$n0 set Y_ 200"

$ns at 0.0 "$n1 set X_ 150"
$ns at 0.0 "$n1 set Y_ 250"

$ns at 0.0 "$n2 set X_ 150"
$ns at 0.0 "$n2 set Y_ 150"

# Right LAN (mirror)
$ns at 0.0 "$n4 set X_ 300"
$ns at 0.0 "$n4 set Y_ 200"

$ns at 0.0 "$n7 set X_ 350"
$ns at 0.0 "$n7 set Y_ 200"

$ns at 0.0 "$n5 set X_ 300"
$ns at 0.0 "$n5 set Y_ 250"

$ns at 0.0 "$n6 set X_ 300"
$ns at 0.0 "$n6 set Y_ 150"

# Fix Z-axis
foreach node "$n0 $n1 $n2 $n3 $n4 $n5 $n6 $n7" {
    $ns at 0.0 "$node set Z_ 0"
}
# -------------------------------
# LAN creation
# -------------------------------
$ns make-lan "$n0 $n1 $n2 $n3" 1000Mb 300ms LL Queue/DropTail Mac/802_3
$ns make-lan "$n4 $n5 $n6 $n7" 1000Mb 300ms LL Queue/DropTail Mac/802_3

# Link between LANs
$ns duplex-link $n3 $n4 100Mb 300ms DropTail
$ns duplex-link-op $n3 $n4 color "green"
$ns duplex-link-op $n3 $n4 orient right

# Error model
set err [new ErrorModel]
$ns lossmodel $err $n3 $n4
$err set rate_ 0.3

# Change to 0.3, 0.5 etc. for different runs

# UDP + CBR traffic
set udp [new Agent/UDP]
$ns attach-agent $n1 $udp

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set fid_ 0
$cbr set packetSize_ 1000
$cbr set interval_ 0.0001

# Receiver
set null [new Agent/Null]
$ns attach-agent $n7 $null

# Connect sender to receiver
$ns connect $udp $null

# Finish procedure
proc finish {} {
    global ns nf tf
    $ns flush-trace
    close $nf
    close $tf
    exec nam lab.nam &
    exec awk -f 11.awk out.tr &
    exit 0
}

# Simulation timing
$ns at 0.1 "$cbr start"
$ns at 3.0 "finish"

# Run simulation
$ns run
