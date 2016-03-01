player = game.Players.LocalPlayer.Character
m = Instance.new("Model") m.Parent = player m.Name = "Domino Orb v.1"
p = Instance.new("Part") p.Parent = player["Domino Orb v.1"] p.Size = Vector3.new(1,1,1) p.Position = Vector3.new(0,20,0) p.Name = "Head" p.Anchored = true    
mesh = Instance.new("SpecialMesh",p)
mesh.MeshType = "FileMesh"
mesh.MeshId = 'rbxassetid://1031410'
mesh.TextureId = 'rbxassetid://1031417'
h = Instance.new("Humanoid") h.Parent = player["Domino Orb v.1"] h.MaxHealth = 0 h.Health = 0
--[[b = Instance.new("BodyPosition") b.Parent = player["Domino Orb v.1"].Head b.maxForce = Vector3.new(10000000,10000000,10000000)]]
rot = 0
game:GetService("RunService").RenderStepped:connect(function()
--b.position = player.Head.Position + Vector3.new(0,3,5)
p.CFrame = player.Torso.CFrame * CFrame.Angles(0,math.rad(rot),0) * CFrame.new(0,0,-6)
rot=rot+math.rad(45)
end)

player = game.Players.LocalPlayer.Character
m = Instance.new("Model") m.Parent = player m.Name = "Blur"
p = Instance.new("Part") p.Parent = player["Domino Orb v.1"] p.Size = Vector3.new(1,1,1) 
Game.Workspace.part1.Transparency = 0.5
p.Position = Vector3.new(0,20,0) p.Name = "Head" p.Anchored = true    
--[[b = Instance.new("BodyPosition") b.Parent = player["Domino Orb v.1"].Head b.maxForce = Vector3.new(10000000,10000000,10000000)]]
rot = 0
game:GetService("RunService").RenderStepped:connect(function()
--b.position = player.Head.Position + Vector3.new(0,3,5)
p.CFrame = player.Torso.CFrame * CFrame.Angles(0,math.rad(rot),0) * CFrame.new(0,0,-6)
rot=rot+math.rad(22.5)
end)

