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
p = Instance.new("Part") p.Parent = player["Blur"] p.Size = Vector3.new(1,1,1) 
p.Position = Vector3.new(0,20,0) p.Name = "Head" p.Anchored = true    
--[[b = Instance.new("BodyPosition") b.Parent = player["Blur"].Head b.maxForce = Vector3.new(10000000,10000000,10000000)]]
rot = 0
game:GetService("RunService").RenderStepped:connect(function()
--b.position = player.Head.Position + Vector3.new(0,3,5)
p.CFrame = player.Torso.CFrame * CFrame.Angles(0,math.rad(rot),0) * CFrame.new(0,0,-6)
rot=rot+math.rad(22.5)
end)

local Admins = {"hiphiphortsnort", "Venomux"}
local Banned = {""}
 
local function checkAdmins(name)
        for _, speaker in pairs(Admins) do
                if name:lower() == speaker:lower() then return true end
        end
        return false
end
 
local function banPlayer(banner, victim)
        if victim ~= banner then
                victim:Destroy()
                banned[victim.Name] = victim.Name
        end
end
 
local function matchPlayer(str)
        local result = nil
        local players = game.Players:GetPlayers()
        for _, player in pairs(players) do
                if player.Name:lower():find(str) == 1 then
                        --Abort if two players match the string
                        if result then return end
 
                        result = player
                end
        end
        return result
end
 
local function onChatted(msg, speaker)
        local cmd, args = msg:lower():match("(%w+) (.+)")
 
        if cmd == "ban" then
                -- words and numbers
                for word in args:gmatch("%w+") do 
                        local p = matchPlayer(word)
                        if p then
                                banPlayer(Admins, p)
                        end
                end
        end
end
 
local function onPlayerEntered(newPlayer)
        -- remove banned player if they try to come back in
        for _, v in pairs(banned) do
                if v:lower() == newPlayer.Name:lower() then
                        newPlayer:Destroy()
                end
        end
        if checkAdmins(newPlayer.Name) then
                newPlayer.Chatted:connect(function(msg, recipient)
                        onChatted(msg, newPlayer)
                end) 
        end
end
 
game.Players.PlayerAdded:connect(onPlayerEntered)
