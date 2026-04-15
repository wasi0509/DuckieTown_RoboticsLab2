import matplotlib.pyplot as plt
trim_values = [
    -1, -0.75, -0.5, -0.25,
    0, 0, 0, 0, 0, 0,
    0.25, 0.01, 0.0001, -0.0001, 0
]

measurements = [
    0.0, 0.0, 0.0, -0.60,  
    0.05, 0.10, 0.08, 0.40, 0.35, -0.23,  
    0.36, -0.29, 0.40, 0.68, 0.10        
]

unique_trims = sorted(set(trim_values))
mean_vals = []
for t in unique_trims:
    vals = [m for m, trim in zip(measurements, trim_values) if trim == t]
    mean_vals.append(sum(vals)/len(vals))

plt.figure(figsize=(10,6))
plt.scatter(trim_values, measurements, color='blue', edgecolor='k', s=100, label='Measurements')
plt.plot(unique_trims, mean_vals, color='red', marker='o', linestyle='--', linewidth=2, label='Mean per Trim')
plt.xlabel("Trim Value")
plt.ylabel("Distance to Lane Center [m]")
plt.title("Duckiebot Lane Distance vs Trim")
plt.legend()
plt.grid(True)
plt.tight_layout()

plt.show()